class customer:
    def __init__(self, stt, name, res1, res2):
        self.stt = stt
        self.name = name
        self.res1 = res1 if res1 <= 10 else res1/10
        self.res2 = res2 if res2 <= 10 else res2/10
        self.amount = (self.res1 + self.res2)/2
    
    def rank(self):
        if self.amount > 9.5:
            return "XUAT SAC"
        elif self.amount >= 8:
            return "DAT"
        elif self.amount >= 5:
            return "CAN NHAC"
        else:
            return "TRUOT"

def submit():
    n = int(input())
    A = []

    for i in range(n):
        name = input()
        res1 = float(input())
        res2 = float(input())

        A.append(customer(i+1, name, res1, res2))
    
    A.sort(key=lambda x: (-x.amount, x.stt))
    for i in A:
        print(f"TS0{i.stt} {i.name} {i.amount:.2f} {i.rank()}")



submit()