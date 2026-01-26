from datetime import datetime

class exam:
    def __init__(self, stt, ma, date, time, group):
        self.stt = stt
        self.ma = ma
        self.date = date
        self.time = time
        self.group = group




def submit():
    n, m = map(int, input().split())
    A = []
    B = dict()

    for i in range(n):
        ma = input()
        name = input()
        B[ma] = name
    for j in range(m):
        temp = input().split()
        ma = temp[0]
        date = datetime.strptime(temp[1], "%d/%m/%Y")
        time = datetime.strptime(temp[2], "%H:%M")
        group = int(temp[3])

        A.append(exam(j+1, ma, date, time, group))

    
    A.sort(key=lambda x:(x.date, x.time, x.ma))
    for i in A:
        print(f"T{i.stt:03d} {i.ma} {B[i.ma]} {i.date.day:02d}/{i.date.month:02d}/{i.date.year} {i.time.hour:02d}:{i.time.minute:02d} {i.group:02d}")



submit()