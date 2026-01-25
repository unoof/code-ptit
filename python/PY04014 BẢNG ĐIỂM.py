class student:
    def __init__(self, stt, name, total):
        self.stt = stt
        self.name = name
        self.average = round(total/12+0.01, 1)
        if self.average >= 9:
            self.lvl = "XUAT SAC"
        elif self.average >= 8:
            self.lvl = "GIOI"
        elif self.average >= 7:
            self.lvl = "KHA"
        elif self.average >= 5:
            self.lvl = "TB"
        else:
            self.lvl = "YEU"


def submit():
    n = int(input())
    A = []

    i = 1
    for _ in range(n):
        name = input().strip()
        temp = list(map(float, input().split()))
        total = sum(temp[:2])*2 + sum(temp[2:])
        A.append(student(i, name, total))
        i+=1
    
    A.sort(key=lambda x: (-x.average, x.stt))
    for j in A:
        print(f"HS{j.stt:02d} {j.name} {j.average} {j.lvl}")



submit()