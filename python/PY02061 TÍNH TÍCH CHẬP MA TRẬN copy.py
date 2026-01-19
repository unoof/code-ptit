def submit():
    n, m = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]
    B = [list(map(int, input().split())) for _ in range(3)]
    ans = 0

    for i in range(1, n-1):
        for j in range(1, m-1):
            cell_sum = 0
            for di in range(3):
                for dj in range(3):
                    cell_sum += A[i-1+di][j-1+dj] * B[di][dj]
            ans += cell_sum
    
    print(ans)














test = int(input())
for i in range(test):
    submit()