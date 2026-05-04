# ===== IMPORT =====
import tkinter as tk
from tkinter import messagebox
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# ===== LOAD DATA =====
try:
    df = pd.read_csv("data.csv")
except:
    print("❌ Không tìm thấy data.csv")
    exit()

# ===== CLEAN DATA =====
df = df.drop(columns=["Unnamed: 0"], errors="ignore")
df.columns = df.columns.str.strip()
df['player'] = df['player'].fillna('').str.strip()

player_list = sorted(df['player'].dropna().unique())

# ===== FORMAT VALUE =====
def format_value(col, val):
    try:
        val = float(val)
        if "pct" in col or "per90" in col or "per_" in col:
            return round(val, 2)
        return int(val) if val.is_integer() else round(val, 2)
    except:
        return val

# ===== FORMAT STAT NAME =====
def format_stat_name(stat):
    return stat.replace("_", " ").title()

# ===== GET DATA =====
def get_player_data(name):
    name = name.strip().lower()
    if not name:
        return None

    result = df[df['player'].str.lower().str.contains(name, na=False)]
    if result.empty:
        return None

    row = result.iloc[0]

    data = {}
    for col in df.columns:
        if col == "player":
            continue

        val = row[col]
        if pd.isna(val) or val == "N/a":
            continue

        data[col] = format_value(col, val)

    return data


# ===== GUI =====
root = tk.Tk()
root.title("Football Manager")
root.geometry("1000x600")

# ===== ICON =====
try:
    root.iconbitmap("icon.ico")
except:
    print("⚠️ Không tìm thấy icon.ico")

player1_data = {}
player2_data = {}
cb1 = {}
cb2 = {}

# ===== AUTOCOMPLETE =====
def update_suggestions(event, entry, listbox):
    text = entry.get().lower()

    if text == "":
        listbox.place_forget()
        return

    matches = sorted(player_list, key=lambda x: (not x.lower().startswith(text), x))
    matches = [p for p in matches if text in p.lower()][:50]

    if not matches:
        listbox.place_forget()
        return

    listbox.delete(0, tk.END)
    for m in matches:
        listbox.insert(tk.END, m)

    x = entry.winfo_rootx() - root.winfo_rootx()
    y = entry.winfo_rooty() - root.winfo_rooty() + entry.winfo_height()

    listbox.place(x=x, y=y, width=entry.winfo_width())


def select_suggestion(event, entry, listbox):
    if listbox.curselection():
        value = listbox.get(listbox.curselection())
        entry.delete(0, tk.END)
        entry.insert(0, value)
        listbox.place_forget()


def hide_listbox(event, listbox):
    listbox.place_forget()


# ===== SCROLL FRAME =====
def create_scroll_frame(parent):
    container = tk.Frame(parent)

    canvas = tk.Canvas(container, width=400, height=400)
    scrollbar = tk.Scrollbar(container, orient="vertical", command=canvas.yview)

    scroll_frame = tk.Frame(canvas)

    scroll_frame.bind(
        "<Configure>",
        lambda e: canvas.configure(scrollregion=canvas.bbox("all"))
    )

    canvas.create_window((0, 0), window=scroll_frame, anchor="nw")
    canvas.configure(yscrollcommand=scrollbar.set)

    canvas.pack(side="left")
    scrollbar.pack(side="right", fill="y")

    # ===== SCROLL FIX (chỉ scroll khi hover) =====
    def _on_mouse_wheel(event):
        canvas.yview_scroll(int(-1*(event.delta/120)), "units")

    def _bind_mouse(event):
        canvas.bind("<MouseWheel>", _on_mouse_wheel)

    def _unbind_mouse(event):
        canvas.unbind("<MouseWheel>")

    canvas.bind("<Enter>", _bind_mouse)
    canvas.bind("<Leave>", _unbind_mouse)

    return container, scroll_frame


# ===== INPUT =====
frame_input = tk.Frame(root)
frame_input.pack(pady=10)

entry1 = tk.Entry(frame_input, width=25)
entry1.grid(row=0, column=0, padx=10)

btn1 = tk.Button(frame_input, text="Search Player 1")
btn1.grid(row=0, column=1)

entry2 = tk.Entry(frame_input, width=25)
entry2.grid(row=0, column=2, padx=10)

btn2 = tk.Button(frame_input, text="Search Player 2")
btn2.grid(row=0, column=3)

listbox1 = tk.Listbox(root, height=8)
listbox2 = tk.Listbox(root, height=8)

entry1.bind("<KeyRelease>", lambda e: update_suggestions(e, entry1, listbox1))
entry2.bind("<KeyRelease>", lambda e: update_suggestions(e, entry2, listbox2))

listbox1.bind("<<ListboxSelect>>", lambda e: select_suggestion(e, entry1, listbox1))
listbox2.bind("<<ListboxSelect>>", lambda e: select_suggestion(e, entry2, listbox2))

entry1.bind("<FocusOut>", lambda e: hide_listbox(e, listbox1))
entry2.bind("<FocusOut>", lambda e: hide_listbox(e, listbox2))


# ===== RESULT =====
frame_result = tk.Frame(root)
frame_result.pack()

container1, frame1 = create_scroll_frame(frame_result)
container1.grid(row=0, column=0, padx=20)

container2, frame2 = create_scroll_frame(frame_result)
container2.grid(row=0, column=1, padx=20)


def clear_frame(frame):
    for widget in frame.winfo_children():
        widget.destroy()


def render(frame, data):
    vars = {}
    data = dict(sorted(data.items()))

    for stat, value in data.items():
        var = tk.BooleanVar()
        pretty_stat = format_stat_name(stat)

        cb = tk.Checkbutton(frame, text=f"{pretty_stat}: {value}", variable=var)
        cb.pack(anchor="w")

        vars[stat] = (var, value)

    return vars


# ===== SEARCH =====
def search1():
    global player1_data, cb1

    data = get_player_data(entry1.get())
    if not data:
        messagebox.showerror("Error", "Không tìm thấy cầu thủ 1")
        return

    player1_data = data
    clear_frame(frame1)
    cb1 = render(frame1, data)


def search2():
    global player2_data, cb2

    data = get_player_data(entry2.get())
    if not data:
        messagebox.showerror("Error", "Không tìm thấy cầu thủ 2")
        return

    player2_data = data
    clear_frame(frame2)
    cb2 = render(frame2, data)


btn1.config(command=search1)
btn2.config(command=search2)


# ===== RADAR (AUTO SCALE) =====
def plot(stats, v1, v2, name1, name2):
    N = len(stats)

    angles = np.linspace(0, 2*np.pi, N, endpoint=False).tolist()

    v1 += v1[:1]
    v2 += v2[:1]
    angles += angles[:1]

    # ===== AUTO SCALE SIZE =====
    size = min(12, 6 + N // 3)

    fig, ax = plt.subplots(figsize=(size, size), subplot_kw=dict(polar=True))

    ax.plot(angles, v1, label=name1)
    ax.fill(angles, v1, alpha=0.25)

    ax.plot(angles, v2, label=name2)
    ax.fill(angles, v2, alpha=0.25)

    ax.set_xticks(angles[:-1])
    ax.set_xticklabels([format_stat_name(s) for s in stats])

    # ===== AUTO SCALE TEXT =====
    label_size = max(6, 12 - N // 3)
    ax.tick_params(axis='x', labelsize=label_size)

    plt.legend()
    plt.tight_layout()
    plt.show()


# ===== COMPARE =====
def compare():
    if not player1_data or not player2_data:
        messagebox.showerror("Error", "Thiếu dữ liệu")
        return

    stats, v1, v2 = [], [], []

    for stat in cb1:
        if cb1[stat][0].get():
            stats.append(stat)
            v1.append(player1_data.get(stat, 0))
            v2.append(player2_data.get(stat, 0))

    if len(stats) < 3:
        messagebox.showerror("Error", "Chọn ít nhất 3 chỉ số")
        return

    # ❌ KHÔNG còn giới hạn max

    if len(stats) > 20:
        messagebox.showwarning("Warning", "Quá nhiều chỉ số → biểu đồ sẽ khó nhìn")

    plot(stats, v1, v2, entry1.get(), entry2.get())


# ===== BUTTON =====
btn_compare = tk.Button(root, text="Compare", command=compare)
btn_compare.pack(pady=20)

root.mainloop()
