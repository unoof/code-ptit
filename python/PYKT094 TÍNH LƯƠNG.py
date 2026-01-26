class worker:
    def __init__(self, id, name, group, salary, days):
        temp = {"A": [10]*3 + [12]*5 + [14]*7 + [20],
                "B": [10]*3 + [11]*5 + [13]*7 + [16],
                "C":  [9]*3 + [10]*5 + [12]*7 + [14],
                "D":  [8]*3 +  [9]*5 + [11]*7 + [13]}
        self.id = id
        self.name = name
        self.group = group
        self.money = salary*days*1000

        try:
            self.money *= temp[id[0]][int(id[1:3])-1]
        except (IndexError):
            self.money *= temp[id[0]][-1]


def submit():
    n = int(input())
    B = dict()

    for i in range(n):
        temp = input().split()
        B[temp[0]] = " ".join(temp[1:])

    m = int(input())
    A = []
    for i in range(m):
        id = input()
        name = input()
        salary = int(input())
        days = int(input())

        A.append(worker(id, name, B[id[3:]], salary, days))

    for i in A:
        print(f"{i.id} {i.name} {i.group} {i.money}")



submit()