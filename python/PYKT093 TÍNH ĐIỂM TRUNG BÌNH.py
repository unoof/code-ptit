class student:
    def __init__(self, stt, name, res1, res2, res3):
        self.stt = stt
        self.name = name
        self.mark = (res1*3 + res2*3 + res3*2)/8+0.0045
        

def submit():
    n = int(input())
    A = []

    for i in range(n):
        ten = input().split()
        name = ' '.join(ten).title()
        res1 = float(input())
        res2 = float(input())
        res3 = float(input())

        A.append(student(i+1, name, res1, res2, res3))

    A.sort(key=lambda x:(-x.mark, x.stt))
    rank = 1
    store = 0
    for i in range(len(A)):
        if i > 0 and A[i].mark != A[i-1].mark:
            rank += store
            store = 1
        else:
            store += 1
        print(f"SV{A[i].stt:02d} {A[i].name} {A[i].mark:.2f} {rank}")



submit()