from datetime import datetime

class customer:
    def __init__(self, name, place, time):
        self.name = name
        self.place = place
        self.id = ""

        for i in place.split():
            self.id += i[0]
        for i in name.split():
            self.id += i[0]

        self.speed = 120/time




def submit():
    n = int(input())
    A = []

    for i in range(n):
        name = input()
        place = input()
        start = datetime.strptime("6:00", "%H:%M")
        end = datetime.strptime(input(), "%H:%M")
        time = (end-start).seconds/3600

        A.append(customer(name, place, time))
    
    A.sort(key=lambda x:(-x.speed))
    for i in A:
        print(f"{i.id} {i.name} {i.place} {round(i.speed)} Km/h")



submit()