from datetime import datetime

class customer:
    def __init__(self, stt, name, total):
        self.stt = stt
        self.name = name
        self.total = total
        self.hour = total//3600
        total -= self.hour*3600
        self.minute = total//60

def submit():
    n = int(input())
    A = []

    for i in range(n):
        stt = input()
        name = input()
        start = datetime.strptime(input(), "%H:%M")
        end = datetime.strptime(input(), "%H:%M")
        time = (end-start).seconds

        A.append(customer(stt, name, time))
    
    A.sort(key=lambda x: (-x.total))
    for i in A:
        print(f"{i.stt} {i.name} {i.hour} gio {i.minute} phut")



submit()