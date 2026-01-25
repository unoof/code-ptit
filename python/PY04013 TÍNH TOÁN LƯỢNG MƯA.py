from datetime import datetime

class Tram:
    def __init__(self, time, amount):
        self.time = time
        self.amount = amount
    
    def average(self):
        return self.amount*60/self.time

def submit():
    n = int(input())
    A = dict()

    for i in range(n):
        name = input().strip()
        start = datetime.strptime(input(), "%H:%M")
        end = datetime.strptime(input(), "%H:%M")
        amount = float(input())
        
        time = (end-start).seconds//60
        if name in A:
            A[name][0] += time
            A[name][1] += amount
        else:
            A[name] = [time, amount]
    
    i = 1
    for key, val in A.items():
        temp = Tram(val[0], val[1])
        print(f"T{i:02d} {key} {temp.average():.2f}")
        i+=1



submit()