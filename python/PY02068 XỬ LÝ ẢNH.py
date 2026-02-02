import sys

def submit():
    n, m, l = map(int, sys.stdin.readline().split())
    A = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    prefix_matrix = [[0]*(m+1) for _ in range(n+1)]

    ans = [[0]*(m-l+1) for _ in range(n-l+1)]
    for i in range(1, n+1):
        for j in range(1, m+1):
            prefix_matrix[i][j] = A[i-1][j-1] + prefix_matrix[i][j-1] + prefix_matrix[i-1][j] - prefix_matrix[i-1][j-1]

    ans = [[0]*(m-l+1) for _ in range(n-l+1)]
    for i in range(n-l+1):
        for j in range(m-l+1):
            ans[i][j] = (prefix_matrix[i+l][j+l] - prefix_matrix[i][j+l] - prefix_matrix[i+l][j] + prefix_matrix[i][j])//(l*l)


    for row in ans:
        print(" ".join(map(str, row)))









test = int(sys.stdin.readline())
for _ in range(test):
    submit()