def submit():
    n, m = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]

    temp = abs(n-m)
    if n > m:
        for i in range(temp-1, -1, -1):
            A.pop(i*2)
    else:
        for j in range(n):
            for i in range(temp-1, -1, -1):
                A[j].pop(i*2+1)

    for i in A:
        print(*i)
submit()