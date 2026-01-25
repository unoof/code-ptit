class customer:
    def __init__(self, stt, name, amount):
        self.stt = stt
        self.name = name
        self.amount = amount
    
    def money(self):
        total = 0
        if self.amount <= 50:
            total += self.amount*100*1.02
        elif self.amount <= 100:
            total += 50*100
            total += (self.amount-50)*150
            total *= 1.03
        else:
            total += 50*100
            total += 50*150
            total += (self.amount-100)*200
            total *= 1.05
        return int(total+0.5)

def submit():
    n = int(input())
    A = []

    for i in range(n):
        name = input().strip()
        start = int(input())
        end = int(input())
        amount = end-start

        A.append(customer(i+1, name, amount))
    
    A.sort(key=lambda x: (-x.money(), x.stt))
    for i in A:
        print(f"KH{i.stt:02d} {i.name} {i.money()}")



submit()