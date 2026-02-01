from math import isqrt

def check(n):
    if n < 2:
        return False
    for i in range(2, isqrt(n)+1):
        if n%i == 0:
            return False
    return True

def submit():
    n, m = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]

    maxi = 0
    ans = []

    for i in range(n):
        for j in range(m):
            if check(A[i][j]):
                if A[i][j] > maxi:
                    maxi = A[i][j]
                    ans.clear()
                    ans.append((i, j))
                elif A[i][j] == maxi:
                    ans.append((i, j))

    if maxi == 0:
        print("NOT FOUND")
    else:
        print(maxi)
        for i in ans:
            print(f"Vi tri [{i[0]}][{i[1]}]")









submit()