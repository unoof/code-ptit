class bill:
    def __init__(self, mmh, name, amount, discount, money):
        self.mmh = mmh
        self.name = name
        self.amount = amount
        self.money = money
        self.discount = discount
        self.total = money*amount - discount




def submit():
    n = int(input())
    A = []

    for i in range(n):
        mmh = input()
        name = input()
        amount = int(input())
        money = int(input())
        discount = int(input())

        A.append(bill(mmh, name, amount, discount, money))
    
    A.sort(key=lambda x:(-x.total))
    for i in A:
        print(f"{i.mmh} {i.name} {i.amount} {i.money} {i.discount} {i.total}")



submit()