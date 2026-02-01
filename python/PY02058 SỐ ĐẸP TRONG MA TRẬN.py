def submit():
    n, m = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]

    num = max(max(i) for i in A) - min(min(i) for i in A)
    ans = []

    for i in range(n):
        for j in range(m):
            if A[i][j] == num:
                ans.append((i, j))

    if len(ans) == 0:
        print("NOT FOUND")
        return
    print(num)
    for i in ans:
        print(f"Vi tri [{i[0]}][{i[1]}]")









submit()