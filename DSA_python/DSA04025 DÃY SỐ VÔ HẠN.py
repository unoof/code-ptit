def submit():
    n = int(input())
    F = [[1, 0],
         [0, 0]]
    M = [[1, 1],
         [1, 0]]
    
    def multiply(A, B):
        C = [[0]*2 for _ in range(2)]
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    C[i][j] = (C[i][j] + A[i][k]*B[k][j])%MOD
        return C

    def power(A, times):
        ans = [[0]*2 for _ in range(2)]
        for i in range(2):
            for j in range(2):
                if i == j:
                    ans[i][j] = 1
        
        while times:
            if times&1:
                ans = multiply(ans, A)
            A = multiply(A, A)
            times >>= 1
        return ans

    ans = power(M, n-1)
    ans = multiply(ans, F)

    print(ans[0][0]%MOD)


MOD = 10**9+7

test = int(input())
for _ in range(test):
    submit()
