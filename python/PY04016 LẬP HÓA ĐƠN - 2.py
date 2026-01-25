from datetime import datetime

class customer:
    def __init__(self, stt, name, room, time, extra):
        self.stt = stt
        self.name = name
        self.room = room
        self.time = time

        temp = extra
        if room[0] == '1':
            temp += 25*time
        elif room[0] == '2':
            temp += 34*time
        elif room[0] == '3':
            temp += 50*time
        else:
            temp += 80*time
        self.money = temp


def submit():
    n = int(input())
    A = []

    for i in range(n):
        name = input().strip()
        room = input().strip()
        start = datetime.strptime(input().strip(), "%d/%m/%Y")
        end = datetime.strptime(input().strip(), "%d/%m/%Y")
        extra = int(input())
        time = (end-start).days

        A.append(customer(i+1, name, room, time+1, extra))
    
    A.sort(key=lambda x:(-x.money))
    for i in A:
        print(f"KH{i.stt:02d} {i.name} {i.room} {i.time} {i.money}")



submit()