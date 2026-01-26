class student:
    def __init__(self, stt, name, mark, place, group):
        self.stt = stt
        self.name = name
        self.mark = mark
        if group == 1:
            self.mark += 1.5
        elif group == 2:
            self.mark += 1
        
        if place != "Kinh": self.mark += 1.5
        self.res = "Do" if self.mark >= 20.5 else "Truot"

def submit():
    n = int(input())
    A = []

    for i in range(n):
        ten = input().split()
        name = ' '.join(ten).title()
        mark = float(input())
        place = input()
        group = int(input())

        A.append(student(i+1, name, mark, place, group))

    A.sort(key=lambda x:(-x.mark, x.stt))
    for i in A:
        print(f"TS{i.stt:02d} {i.name} {i.mark:.1f} {i.res}")



submit()