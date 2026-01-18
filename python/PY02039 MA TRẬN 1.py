def submit():
    n = int(input())
    A = [list(map(int, input().split())) for _ in range(n)]
    k = int(input())

    total = 0
    for i in range(n):
        for j in range(n):
            if j < i:
                total -= A[i][j]
            elif j > i:
                total += A[i][j]

    print("YES" if abs(total) < k else "NO")
    print(abs(total))




submit()