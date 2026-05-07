# ===== IMPORT =====
import customtkinter as ctk
import tkinter as tk
from tkinter import messagebox
import requests
import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import subprocess
import sys, time
import unicodedata

# ===== COLOR =====
BG = "#0B0F0C"
CARD = "#121A14"
PRIMARY = "#00FF85"
SECONDARY = "#00C853"
TEXT = "#E8F5E9"

ctk.set_appearance_mode("dark")
api = subprocess.Popen(
    ['cmd', '/c', sys.executable, 'code/restful_api.py'],
    shell=True   # required for 'start' command on windows
)
API_URL = "http://127.0.0.1:5000"

# ===== NORMALIZE =====
def normalize(text):
    return ''.join(
        c for c in unicodedata.normalize('NFD', str(text))
        if unicodedata.category(c) != 'Mn'
    ).lower()

def wait_for_server(url, timeout=30, interval=0.5):
    """keep checking until server responds or timeout"""
    start = time.time()
    while time.time() - start < timeout:
        try:
            requests.get(url)
            return True
        except requests.ConnectionError:
            time.sleep(interval)
    return False

# ===== LOAD PLAYER LIST =====
def load_players():
    try:
        ready = wait_for_server(API_URL)
        if ready:
            res = requests.get(API_URL + "/players")
            if res.status_code == 200:
                return res.json()
        else:
            return []
    except:
        pass
    return []

player_list = load_players()

# ===== FORMAT =====
def format_value(col, val):
    try:
        val = float(val)
        return int(val) if val.is_integer() else round(val, 2)
    except:
        return val

def format_stat_name(stat):
    return stat.replace("_", " ").title()

# ===== GET DATA FROM API =====
def get_player_data(name):
    try:
        res = requests.post(API_URL + "/search", data={"user_input": name})

        if res.status_code != 200:
            return None

        raw = res.json()
        del raw["player_norm"]

        columns = ['nationality','position','team','age','birth_year','games','games_starts','minutes','minutes_90s','goals','assists','goals_assists',
                'goals_pens','pens_made','pens_att','cards_yellow','cards_red','goals_per90','assists_per90','goals_assists_per90','goals_pens_per90',
                'goals_assists_pens_per90','gk_goals_against','gk_goals_against_per90','gk_shots_on_target_against','gk_saves','gk_save_pct','gk_wins',
                'gk_ties','gk_losses','gk_clean_sheets','gk_clean_sheets_pct','gk_pens_att','gk_pens_allowed','gk_pens_saved','gk_pens_missed',
                'gk_pens_save_pct','shots','shots_on_target','shots_on_target_pct','shots_per90','shots_on_target_per90','goals_per_shot',
                'goals_per_shot_on_target','minutes_per_game','minutes_pct','minutes_per_start','games_complete','games_subs','minutes_per_sub',
                'unused_subs','points_per_game','on_goals_for','on_goals_against','plus_minus','plus_minus_per90','plus_minus_wowy',
                'cards_yellow_red','fouls','fouled','offsides','crosses','interceptions','tackles_won','pens_won','pens_conceded','own_goals']
        
        df = pd.DataFrame([raw])
        df = df.reindex(columns=columns).replace('N/a', np.nan).dropna(axis=1)
        data = df.iloc[0].to_dict()

        return data

    except Exception as e:
        print("API error:", e)
        return None

# ===== GUI =====
root = ctk.CTk()
root.title("Football Analytics Pro ⚽")
root.geometry("1100x650")
root.configure(fg_color=BG)

try:
    root.iconbitmap("icon.ico")
except:
    pass

# ===== INPUT =====
frame_input = ctk.CTkFrame(root, fg_color=CARD, corner_radius=15)
frame_input.pack(padx=20, pady=15, fill="x")

frame_input.grid_columnconfigure(0, weight=1)
frame_input.grid_columnconfigure(2, weight=1)

entry1 = ctk.CTkEntry(frame_input, placeholder_text="Player 1")
entry1.grid(row=0, column=0, padx=10, pady=10, sticky="ew")

btn1 = ctk.CTkButton(
    frame_input,
    text="Search",
    fg_color=PRIMARY,
    hover_color=SECONDARY,
    text_color="black"
)
btn1.grid(row=0, column=1, padx=10)

entry2 = ctk.CTkEntry(frame_input, placeholder_text="Player 2")
entry2.grid(row=0, column=2, padx=10, pady=10, sticky="ew")

btn2 = ctk.CTkButton(
    frame_input,
    text="Search",
    fg_color=PRIMARY,
    hover_color=SECONDARY,
    text_color="black"
)
btn2.grid(row=0, column=3, padx=10)

# ===== AUTOCOMPLETE =====
listbox = tk.Listbox(root, bg=CARD, fg=TEXT,
                     selectbackground=PRIMARY, highlightthickness=0,
                     font=("Arial", 14))

active_entry = None

def update_suggestions(entry):
    global active_entry
    active_entry = entry

    text = entry.get()

    if text == "":
        listbox.place_forget()
        return

    text_norm = normalize(text)

    all_matches = [p for p in player_list if text_norm in normalize(p)]

    # sort — names starting with the text come first
    starts_with = [p for p in all_matches if normalize(p).startswith(text_norm)]
    contains    = [p for p in all_matches if not normalize(p).startswith(text_norm)]

    matches = (starts_with + contains)[:20]

    if not matches:
        listbox.place_forget()
        return

    listbox.delete(0, tk.END)
    for m in matches:
        listbox.insert(tk.END, m)

    x = entry.winfo_rootx() - root.winfo_rootx()
    y = entry.winfo_rooty() - root.winfo_rooty() + entry.winfo_height()

    visible_items = min(len(matches), 6)
    
    listbox.config(height=visible_items)
    listbox.place(x=x, y=y, width=entry.winfo_width())
    listbox.lift()

def select_suggestion(event):
    global active_entry
    if listbox.curselection():
        value = listbox.get(listbox.curselection())
        active_entry.delete(0, "end")
        active_entry.insert(0, value)
        listbox.place_forget()

entry1.bind("<KeyRelease>", lambda e: update_suggestions(entry1))
entry2.bind("<KeyRelease>", lambda e: update_suggestions(entry2))
listbox.bind("<<ListboxSelect>>", select_suggestion)

# ===== RESULT =====
frame_result = ctk.CTkFrame(root, fg_color=CARD, corner_radius=15)
frame_result.pack(padx=20, pady=10, fill="both", expand=True)

frame1 = ctk.CTkScrollableFrame(frame_result)
frame1.pack(side="left", expand=True, fill="both", padx=10, pady=10)

frame2 = ctk.CTkScrollableFrame(frame_result)
frame2.pack(side="right", expand=True, fill="both", padx=10, pady=10)

player1_data, player2_data = {}, {}
cb1, cb2 = {}, {}

def clear_frame(frame):
    for w in frame.winfo_children():
        w.destroy()

def render(frame, data):
    vars = {}

    for stat, value in data.items():
        # 🔥 FILTER LẦN 2 (CHO CHẮC)
        if str(value).lower() in ["n/a", "na"]:
            continue

        var = ctk.BooleanVar()

        cb = ctk.CTkCheckBox(
            frame,
            text=f"{format_stat_name(stat)}: {value}",
            variable=var
        )
        cb.pack(anchor="w")

        vars[stat] = (var, value)

    return vars

# ===== SEARCH =====
def search1():
    global player1_data, cb1
    data = get_player_data(entry1.get())

    if not data:
        messagebox.showerror("Error", "Không tìm thấy")
        return

    player1_data = data
    clear_frame(frame1)
    cb1 = render(frame1, data)

def search2():
    global player2_data, cb2
    data = get_player_data(entry2.get())

    if not data:
        messagebox.showerror("Error", "Không tìm thấy")
        return

    player2_data = data
    clear_frame(frame2)
    cb2 = render(frame2, data)

btn1.configure(command=search1)
btn2.configure(command=search2)

# ===== RADAR CHART =====
def plot(stats, v1, v2, name1, name2):
    angles = np.linspace(0, 2*np.pi, len(stats), endpoint=False).tolist()

    v1 = v1 + v1[:1]
    v2 = v2 + v2[:1]
    angles = angles + angles[:1]

    fig, ax = plt.subplots(subplot_kw=dict(polar=True))

    ax.plot(angles, v1, label=name1)
    ax.fill(angles, v1, alpha=0.25)

    ax.plot(angles, v2, label=name2)
    ax.fill(angles, v2, alpha=0.25)

    ax.set_xticks(angles[:-1])
    ax.set_xticklabels([format_stat_name(s) for s in stats])

    plt.legend()
    plt.show()

# ===== COMPARE =====
def compare():
    if player1_data and player2_data:
        stats, v1, v2 = [], [], []

        for stat in cb1:
            if cb1[stat][0].get():
                stats.append(stat)
                v1.append(player1_data.get(stat, 0))
                v2.append(player2_data.get(stat, 0))

        for stat in cb2:
            if cb2[stat][0].get() and stat not in stats:
                stats.append(stat)
                v1.append(player1_data.get(stat, 0))
                v2.append(player2_data.get(stat, 0))

        if len(stats) < 3:
            messagebox.showerror("Error", "Chọn ít nhất 3 chỉ số")
            return

        plot(stats, v1, v2, entry1.get(), entry2.get())
    else:
        if not player1_data and not player2_data:
            messagebox.showerror("Error", "Hãy chọn 2 cầu thủ")
            return
        messagebox.showerror("Error", "Chọn cầu thủ thứ 2") if not player2_data else messagebox.showerror("Error", "Chọn cầu thủ thứ 1")

btn_compare = ctk.CTkButton(
    root,
    text="Compare",
    command=compare,
    fg_color=PRIMARY,
    hover_color=SECONDARY,
    text_color="black"
)
btn_compare.pack(pady=15, padx=20, fill="x")

#kill api after run finish
def kill_port(port=5000):
    try:
        # find PID using the port
        result = subprocess.run(
            ['netstat', '-ano'],
            capture_output=True, text=True
        )
        for line in result.stdout.splitlines():
            if f':{port}' in line and 'LISTENING' in line:
                pid = line.strip().split()[-1]
                subprocess.run(['taskkill', '/PID', pid, '/F'])
                print(f'killed PID {pid} on port {port}')
    except Exception as e:
        print(f'kill_port error: {e}')

def on_close():
    try:
        api.terminate()
        try:
            api.wait(timeout=5)   # give it 5 seconds to shut down cleanly
        except subprocess.TimeoutExpired:
            api.kill()            # force kill if it didn't stop in time
    except Exception as e:
        print(f'Error terminating API: {e}')
    finally:
        kill_port(5000)
        root.destroy()           # always close the window

# ===== RUN =====
root.protocol("WM_DELETE_WINDOW", on_close)
root.mainloop()