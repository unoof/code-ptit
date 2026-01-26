class teacher:
    def __init__(self, stt, name, mst, tin, chuyen_mon):
        self.stt = stt
        self.name = name
        self.mark = tin*2 + chuyen_mon + (5-int(mst[1]) if 5-int(mst[1]) != 1 else 0)*0.5
        self.res = "TRUNG TUYEN" if self.mark > 18 else "LOAI"

        if mst[0] == "A":
            self.subject = "TOAN"
        elif mst[0] == "B":
            self.subject = "LY"
        else:
            self.subject = "HOA"




def submit():
    n = int(input())
    A = []

    for i in range(n):
        name = input()
        mst = input()
        res1 = float(input())
        res2 = float(input())

        A.append(teacher(i+1, name, mst, res1, res2))
    
    A.sort(key=lambda x:(-x.mark))
    for i in A:
        print(f"GV{i.stt:02d} {i.name} {i.subject} {i.mark:.1f} {i.res}")



submit()