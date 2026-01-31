from math import comb

def submit():
    n = int(input())
    A = [list(input()) for _ in range(n)]
    B = [[0]*n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            B[j][i] = A[i][j]

    total = 0
    for i in A:
        total += comb(i.count('C'),2)
    for i in B:
        total += comb(i.count('C'),2)
    print(total)





submit()