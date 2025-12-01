def multiply(A, B, n):
    C = [[0]*n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += (A[i][k]*B[k][j])
            C[i][j] %= MOD
    return C

def setup(A, n, k):
    ans = [[0]*n for _ in range(n)]
    for i in range(n):
        ans[i][i] = 1
    
    while k > 0:
        if k&1:
            ans = multiply(ans, A, n)
        A = multiply(A, A, n)
        k >>= 1

    return ans


def submit():
    n, k = map(int, input().split())

    M = []
    for i in range(n):
        A = list(map(int, input().split()))
        M.append(A[:])
    
    ans = setup(M, n, k)

    for i in ans:
        print(" ".join(map(str, i)))


MOD = 1000000007

test = int(input())
for i in range(test):
    submit()