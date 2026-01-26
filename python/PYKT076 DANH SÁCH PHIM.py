from datetime import datetime

class phim:
    def __init__(self, stt, loai, time, film, ep):
        self.stt = stt
        self.loai = loai
        self.time = time
        self.film = film
        self.ep = ep




def submit():
    n, m = map(int, input().split())
    A = []
    B = dict()

    for i in range(n):
        B[i+1] = input()
    for j in range(m):
        ma = input()
        time = datetime.strptime(input().strip(), "%d/%m/%Y")
        film = input()
        ep = int(input())

        A.append(phim(j+1, B[int(ma[2:])], time, film, ep))

    
    A.sort(key=lambda x:(x.time, x.film, -x.ep))
    for i in A:
        print(f"P{i.stt:03d} {i.loai} {i.time.day:02d}/{i.time.month:02d}/{i.time.year} {i.film} {i.ep}")



submit()