class electric:
    def __init__(self, id, name, group, used):
        temp = {"A": 100,
                "B": 500,
                "C": 200}
        self.id = id
        self.name = name
        if used > temp[group]:
            self.overload = (used - temp[group])*1000
            self.VAT = self.overload//20
            self.money = temp[group]*450
        else:
            self.money = used*450
            self.overload = 0
            self.VAT = 0
        self.total = self.money + self.overload + self.VAT


def submit():
    n = int(input())
    A = []

    for i in range(n):
        temp = input().strip().split()
        name = " ".join(i.title() for i in temp)
        temp = input().split()
        A.append(electric(i+1, name, temp[0], int(temp[2]) - int(temp[1])))

    A.sort(key=lambda x:(-x.total))
    for i in A:
        print(f"KH{i.id:02d} {i.name} {i.money} {i.overload} {i.VAT} {i.total}")



submit()