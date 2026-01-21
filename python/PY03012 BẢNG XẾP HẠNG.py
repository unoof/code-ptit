def submit():
    n = int(input())
    A = []
    for i in range(n):
        s = input()
        c, t = map(int, input().split())
        A.append([s, c, t])

    A.sort(key=lambda x:(-x[1], x[2], x[0]))
    for i in A:
        print(f"{i[0]} {i[1]} {i[2]}")






submit()