def submit():
    n, k = map(int, input().split())
    A = []
    for i in range(n):
        A.append(list(map(int, input().split())))

    def multiply(A, B, n):
        C = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    C[i][j] = (C[i][j] + A[i][k]*B[k][j])%MOD

        return C

    def power(A, n, times):
        ans = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i == j:
                    ans[i][j] = 1
        
        while times:
            if times&1:
                ans = multiply(ans, A, n)
            A = multiply(A, A, n)
            times >>= 1
        return ans
    
    A = power(A, n, k)
    total = 0

    for i in range(n):
        total = (total + A[i][n-1])%MOD
    
    print(total%MOD)


MOD = 10**9+7

test = int(input())
for _ in range(test):
    submit()
