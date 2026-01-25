class student:
    def __init__(self, msv, name, box, mark):
        self.msv = msv
        self.name = name
        self.box = box

        total = 10
        for i in mark:
            if i == "m":
                total -= 1
            elif i == "v":
                total -= 2
        self.mark = total if total >= 0 else 0


def submit():
    n = int(input())
    A = dict()
    save = []

    for i in range(n):
        msv = input()
        name = input()
        box = input()

        A[msv] = [name, box]
    
    for i in range(n):
        temp = input().split()
        A[temp[0]].append(temp[1])
    
    for key, val in A.items():
        save.append(student(key, val[0], val[1], val[2]))
    
    for i in save:
        print(f"{i.msv} {i.name} {i.box} {i.mark}", "KDDK" if i.mark == 0 else "")



submit()