# ===== IMPORT =====

# Thư viện giao diện CustomTkinter
import customtkinter as ctk

# Thư viện tkinter gốc
import tkinter as tk

# Hiển thị messagebox thông báo
from tkinter import messagebox

# Gửi request tới REST API
import requests

# Thư viện vẽ biểu đồ
import matplotlib

# Sử dụng backend TkAgg cho matplotlib
matplotlib.use("TkAgg")

# Import pyplot để vẽ chart
import matplotlib.pyplot as plt

# Xử lý mảng số học
import numpy as np

# Xử lý dữ liệu dạng bảng
import pandas as pd

# Chạy tiến trình API nền
import subprocess

# Thư viện hệ thống và thời gian
import sys, time

# Chuẩn hóa unicode
import unicodedata


# ===== COLOR =====

# Màu nền ứng dụng
BG = "#0B0F0C"

# Màu card/frame
CARD = "#121A14"

# Màu nút chính
PRIMARY = "#00FF85"

# Màu hover nút
SECONDARY = "#00C853"

# Màu chữ
TEXT = "#E8F5E9"


# Bật dark mode cho CustomTkinter
ctk.set_appearance_mode("dark")


# Chạy REST API bằng subprocess
api = subprocess.Popen(
    ['cmd', '/c', sys.executable, 'code/restful_api.py'],
    shell=True   # cần shell=True trên Windows
)

# URL API local
API_URL = "http://127.0.0.1:5000"


# ===== NORMALIZE =====

# Chuẩn hóa text thành không dấu để tìm kiếm
def normalize(text):

    return ''.join(
        c for c in unicodedata.normalize('NFD', str(text))
        if unicodedata.category(c) != 'Mn'
    ).lower()


# Kiểm tra server API đã chạy chưa
def wait_for_server(url, timeout=30, interval=0.5):

    # Lưu thời gian bắt đầu
    start = time.time()

    # Kiểm tra liên tục tới khi timeout
    while time.time() - start < timeout:

        try:
            requests.get(url)
            return True

        # Nếu chưa kết nối được thì đợi
        except requests.ConnectionError:
            time.sleep(interval)

    return False


# ===== LOAD PLAYER LIST =====

# Load danh sách cầu thủ từ API
def load_players():

    try:

        # Chờ API khởi động
        ready = wait_for_server(API_URL)

        # Nếu API sẵn sàng
        if ready:

            # Gửi request lấy player list
            res = requests.get(API_URL + "/players")

            # Nếu request thành công
            if res.status_code == 200:
                return res.json()

        else:
            return []

    except:
        pass

    return []


# Lưu danh sách cầu thủ
player_list = load_players()


# ===== FORMAT =====

# Format dữ liệu số
def format_value(col, val):
    try:
        val = float(val)
        if "pct" in col or "per90" in col or "per_" in col:
            return round(val, 2)
        return int(val) if val.is_integer() else round(val, 2)
    except:
        return val


# Format tên chỉ số dễ đọc hơn
def format_stat_name(stat):

    return stat.replace("_", " ").title()


# ===== GET DATA FROM API =====

# Lấy dữ liệu cầu thủ từ API
def get_player_data(name):
    
    try:

        # Nếu tên rỗng
        if not name:
            return {}

        # Gửi request tìm kiếm cầu thủ
        res = requests.post(API_URL + "/search", data={"user_input": name})

        # Nếu request lỗi
        if res.status_code != 200:
            return None

        # Lấy dữ liệu json
        raw = res.json()

        # Xóa cột normalize
        raw.pop("player_norm", None)

        # Danh sách cột dữ liệu cần hiển thị
        columns = [
            'nationality','position','team','age','birth_year',
            'games','games_starts','minutes','minutes_90s',
            'goals','assists','goals_assists','goals_pens',
            'pens_made','pens_att','cards_yellow','cards_red',
            'goals_per90','assists_per90','goals_assists_per90',
            'goals_pens_per90','goals_assists_pens_per90',
            'gk_goals_against','gk_goals_against_per90',
            'gk_shots_on_target_against','gk_saves',
            'gk_save_pct','gk_wins','gk_ties','gk_losses',
            'gk_clean_sheets','gk_clean_sheets_pct',
            'gk_pens_att','gk_pens_allowed','gk_pens_saved',
            'gk_pens_missed','gk_pens_save_pct',
            'shots','shots_on_target','shots_on_target_pct',
            'shots_per90','shots_on_target_per90',
            'goals_per_shot','goals_per_shot_on_target',
            'minutes_per_game','minutes_pct',
            'minutes_per_start','games_complete',
            'games_subs','minutes_per_sub','unused_subs',
            'points_per_game','on_goals_for',
            'on_goals_against','plus_minus',
            'plus_minus_per90','plus_minus_wowy',
            'cards_yellow_red','fouls','fouled',
            'offsides','crosses','interceptions',
            'tackles_won','pens_won',
            'pens_conceded','own_goals'
        ]

        # Tạo DataFrame từ dữ liệu json
        df = pd.DataFrame([raw])

        # Sắp xếp lại cột và xóa dữ liệu N/a
        df = df.reindex(columns=columns).replace('N/a', np.nan).dropna(axis=1)

        # Chuyển dữ liệu thành dictionary
        data = df.iloc[0].to_dict()

        return data

    except Exception as e:

        print("API error:", e)
        return None


# ===== GUI =====

# Tạo cửa sổ chính
root = ctk.CTk()

# Tiêu đề ứng dụng
root.title("Football Analytics Pro ⚽")

# Kích thước cửa sổ
root.geometry("1100x650")

# Màu nền cửa sổ
root.configure(fg_color=BG)

try:

    # Đặt icon cho ứng dụng
    root.iconbitmap("icon.ico")

except:
    pass


# ===== INPUT =====

# Frame nhập dữ liệu
frame_input = ctk.CTkFrame(root, fg_color=CARD, corner_radius=15)

# Hiển thị frame
frame_input.pack(padx=20, pady=15, fill="x")

# Cho phép cột co giãn
frame_input.grid_columnconfigure(0, weight=1)
frame_input.grid_columnconfigure(2, weight=1)


# Ô nhập cầu thủ thứ nhất
entry1 = ctk.CTkEntry(frame_input, placeholder_text="Player 1")

entry1.grid(row=0, column=0, padx=10, pady=10, sticky="ew")


# Nút search cầu thủ 1
btn1 = ctk.CTkButton(
    frame_input,
    text="Search",
    fg_color=PRIMARY,
    hover_color=SECONDARY,
    text_color="black"
)

btn1.grid(row=0, column=1, padx=10)


# Ô nhập cầu thủ thứ hai
entry2 = ctk.CTkEntry(frame_input, placeholder_text="Player 2")

entry2.grid(row=0, column=2, padx=10, pady=10, sticky="ew")


# Nút search cầu thủ 2
btn2 = ctk.CTkButton(
    frame_input,
    text="Search",
    fg_color=PRIMARY,
    hover_color=SECONDARY,
    text_color="black"
)

btn2.grid(row=0, column=3, padx=10)


# ===== AUTOCOMPLETE =====

# Listbox hiển thị gợi ý tên cầu thủ
listbox = tk.Listbox(
    root,
    bg=CARD,
    fg=TEXT,
    selectbackground=PRIMARY,
    highlightthickness=0,       
    font=("Arial", 14)
)

# Entry hiện tại đang được chọn
active_entry = None


# Cập nhật gợi ý autocomplete
def update_suggestions(entry):

    global active_entry

    active_entry = entry

    # Lấy text người dùng nhập
    text = entry.get()

    # Nếu text rỗng thì ẩn listbox
    if text == "":
        listbox.place_forget()
        return

    # Chuẩn hóa text
    text_norm = normalize(text)

    # Tìm tên cầu thủ chứa keyword
    all_matches = [p for p in player_list if text_norm in normalize(p)]

    # Ưu tiên tên bắt đầu bằng keyword
    starts_with = [p for p in all_matches if normalize(p).startswith(text_norm)]

    # Các tên chỉ chứa keyword
    contains = [p for p in all_matches if not normalize(p).startswith(text_norm)]

    # Gộp danh sách
    matches = (starts_with + contains)[:20]

    # Nếu không có kết quả
    if not matches:
        listbox.place_forget()
        return

    # Xóa dữ liệu cũ
    listbox.delete(0, tk.END)

    # Thêm dữ liệu mới
    for m in matches:
        listbox.insert(tk.END, m)

    # Lấy vị trí entry
    x = entry.winfo_rootx() - root.winfo_rootx()
    y = entry.winfo_rooty() - root.winfo_rooty() + entry.winfo_height()

    # Giới hạn số item hiển thị
    visible_items = min(len(matches), 6)

    # Set chiều cao listbox
    listbox.config(height=visible_items)

    # Hiển thị listbox
    listbox.place(x=x, y=y, width=entry.winfo_width())

    # Đưa listbox lên trên
    listbox.lift()


# Chọn cầu thủ từ autocomplete
def select_suggestion(event):

    global active_entry

    # Nếu có item được chọn
    if listbox.curselection():

        # Lấy giá trị item
        value = listbox.get(listbox.curselection())

        # Xóa text cũ
        active_entry.delete(0, "end")

        # Chèn text mới
        active_entry.insert(0, value)

        # Ẩn listbox
        listbox.place_forget()


# Bắt sự kiện nhập text
entry1.bind("<KeyRelease>", lambda e: update_suggestions(entry1))
entry2.bind("<KeyRelease>", lambda e: update_suggestions(entry2))

# Bắt sự kiện chọn item
listbox.bind("<<ListboxSelect>>", select_suggestion)


# ===== RESULT =====

# Frame hiển thị kết quả
frame_result = ctk.CTkFrame(root, fg_color=CARD, corner_radius=15)

frame_result.pack(padx=20, pady=10, fill="both", expand=True)


# Frame hiển thị player 1
frame1 = ctk.CTkScrollableFrame(frame_result)

frame1.pack(side="left", expand=True, fill="both", padx=10, pady=10)


# Frame hiển thị player 2
frame2 = ctk.CTkScrollableFrame(frame_result)

frame2.pack(side="right", expand=True, fill="both", padx=10, pady=10)


# Lưu dữ liệu cầu thủ
player1_data, player2_data = {}, {}

# Lưu checkbox các chỉ số
cb1, cb2 = {}, {}


# Xóa dữ liệu frame
def clear_frame(frame):

    # Xóa toàn bộ widget
    for w in frame.winfo_children():
        w.destroy()

    # Scroll về đầu
    frame._parent_canvas.yview_moveto(0)


# Hiển thị dữ liệu cầu thủ
def render(frame, data):

    vars = {}

    # Duyệt từng chỉ số
    for stat, value in data.items():

        # Bỏ dữ liệu không hợp lệ
        if str(value).lower() in ["n/a", "na"]:
            continue

        # Biến checkbox
        var = ctk.BooleanVar()

        # Tạo checkbox
        cb = ctk.CTkCheckBox(
            frame,
            text=f"{format_stat_name(stat)}: {format_value(stat, value)}",
            variable=var
        )

        cb.pack(anchor="w")

        # Lưu checkbox
        vars[stat] = (var, value)

    return vars


# ===== SEARCH =====

# Tìm kiếm cầu thủ thứ nhất
def search1():

    global player1_data, cb1

    # Nếu input rỗng
    if not entry1.get().strip():

        clear_frame(frame1)

        player1_data = None
        return

    # Lấy dữ liệu cầu thủ
    data = get_player_data(entry1.get())

    # Nếu không tìm thấy
    if not data:

        messagebox.showerror("Error", "Không tìm thấy")

        clear_frame(frame1)

        player1_data = None
        return

    # Lưu dữ liệu
    player1_data = data

    # Xóa dữ liệu cũ
    clear_frame(frame1)

    # Render dữ liệu mới
    cb1 = render(frame1, data)


# Tìm kiếm cầu thủ thứ hai
def search2():

    global player2_data, cb2

    # Nếu input rỗng
    if not entry2.get().strip():

        clear_frame(frame2)

        player2_data = None
        return

    # Lấy dữ liệu cầu thủ
    data = get_player_data(entry2.get())

    # Nếu không tìm thấy
    if not data:

        messagebox.showerror("Error", "Không tìm thấy")

        clear_frame(frame2)

        player2_data = None
        return

    # Lưu dữ liệu
    player2_data = data

    # Xóa dữ liệu cũ
    clear_frame(frame2)

    # Render dữ liệu mới
    cb2 = render(frame2, data)


# Gán sự kiện click nút search
btn1.configure(command=search1)
btn2.configure(command=search2)


# ===== RADAR CHART =====
def plot(stats, v1, v2, name1, name2):

    # số lượng stat
    N = len(stats)

    # chia góc radar
    angles = np.linspace(
        0,
        2 * np.pi,
        N,
        endpoint=False
    ).tolist()

    # nối điểm đầu để khép kín radar
    v1 = v1 + v1[:1]
    v2 = v2 + v2[:1]

    angles = angles + angles[:1]

    # ===== FIGURE =====
    fig, ax = plt.subplots(
        figsize=(8, 8),
        subplot_kw=dict(polar=True)
    )

    # ===== PLAYER 1 =====
    ax.plot(
        angles,
        v1,
        linewidth=2,
        label=name1,
        color="#00FF85"
    )

    ax.fill(
        angles,
        v1,
        alpha=0.25,
        color="#00FF85"
    )

    # ===== PLAYER 2 =====
    ax.plot(
        angles,
        v2,
        linewidth=2,
        label=name2,
        color="#0094FF"
    )

    ax.fill(
        angles,
        v2,
        alpha=0.25,
        color="#0094FF"
    )

    # ===== LABEL STAT =====
    ax.set_xticks(angles[:-1])

    ax.set_xticklabels(
        [format_stat_name(s) for s in stats],
        fontsize=9
    )

    # ===== TITLE =====
    plt.title(
        f"{name1} vs {name2}",
        size=16,
        pad=20
    )

    # ===== LEGEND =====
    plt.legend(
        loc='upper right',
        bbox_to_anchor=(1.2, 1.1)
    )

    # ===== SHOW =====
    plt.tight_layout()

    plt.show()

# ===== COMPARE =====
# So sánh 2 cầu thủ
def compare():

    # kiểm tra đã chọn đủ 2 cầu thủ chưa
    if player1_data and player2_data:

        stats, v1, v2 = [], [], []

        # ===== PLAYER 1 =====
        for stat in cb1:

            # nếu checkbox được tick
            if cb1[stat][0].get():

                val1 = player1_data.get(stat, 0)
                val2 = player2_data.get(stat, 0)

                # ép float
                try:
                    val1 = float(val1)
                    val2 = float(val2)

                except:
                    continue

                # KHÔNG normalize nữa
                # giữ nguyên số thật

                stats.append(stat)

                v1.append(val1)
                v2.append(val2)

        # ===== PLAYER 2 =====
        for stat in cb2:

            # nếu checkbox được tick và chưa tồn tại
            if cb2[stat][0].get() and stat not in stats:

                val1 = player1_data.get(stat, 0)
                val2 = player2_data.get(stat, 0)

                # ép float
                try:
                    val1 = float(val1)
                    val2 = float(val2)

                except:
                    continue

                # KHÔNG normalize

                stats.append(stat)

                v1.append(val1)
                v2.append(val2)

        # tối thiểu 3 stat
        if len(stats) < 3:

            messagebox.showerror(
                "Error",
                "Chọn ít nhất 3 chỉ số"
            )
            return

        # vẽ biểu đồ
        plot(
            stats,
            v1,
            v2,
            entry1.get(),
            entry2.get()
        )

    else:

        # chưa chọn đủ cầu thủ
        if not player1_data and not player2_data:

            messagebox.showerror(
                "Error",
                "Hãy chọn 2 cầu thủ"
            )
            return

        #   thiếu 1 trong 2 cầu thủ
        messagebox.showerror(
            "Error",
            "Chọn cầu thủ thứ 2"
        ) if not player2_data else messagebox.showerror(
            "Error",
            "Chọn cầu thủ thứ 1"
        )

# Nút compare
btn_compare = ctk.CTkButton(
    root,
    text="Compare",
    command=compare,
    fg_color=PRIMARY,
    hover_color=SECONDARY,
    text_color="black"
)

btn_compare.pack(pady=15, padx=20, fill="x")


# ===== CLOSE APP =====

# Kill tiến trình theo port
def kill_port(port=5000):

    try:

        # Lấy danh sách port đang chạy
        result = subprocess.run(
            ['netstat', '-ano'],    
            capture_output=True,
            text=True
        )

        # Duyệt từng dòng
        for line in result.stdout.splitlines():

            # Nếu đúng port đang listen
            if f':{port}' in line and 'LISTENING' in line:

                # Lấy PID
                pid = line.strip().split()[-1]

                # Kill process
                subprocess.run(['taskkill', '/PID', pid, '/F'])

                print(f'killed PID {pid} on port {port}')

    except Exception as e:

        print(f'kill_port error: {e}')


# Xử lý khi đóng ứng dụng
def on_close():

    try:

        # Tắt API
        api.terminate()

        try:

            # Chờ API đóng
            api.wait(timeout=5)

        except subprocess.TimeoutExpired:

            # Force kill nếu chưa đóng
            api.kill()

    except Exception as e:

        print(f'Error terminating API: {e}')

    finally:

        # Kill port API
        kill_port(5000)

        # Đóng giao diện
        root.destroy()


# ===== RUN =====

# Bắt sự kiện đóng cửa sổ
root.protocol("WM_DELETE_WINDOW", on_close)

# Chạy ứng dụng
root.mainloop()