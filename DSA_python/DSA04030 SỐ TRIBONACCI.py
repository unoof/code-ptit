def multiply(A, B):
    C = [[0]*4 for _ in range(4)]

    for i in range(4):
        for j in range(4):
            for k in range(4):
                C[i][j] += A[i][k]*B[k][j]
            C[i][j] %=MOD

    return C

def setup(A, n):
    ans = [[0]*4 for _ in range(4)]
    for i in range(4):
        ans[i][i] = 1
    
    while n > 0:
        if n&1:
            ans = multiply(ans, A)
        A = multiply(A, A)
        n >>= 1

    return ans


def submit():
    n = int(input())
    
    if n <= 2:
        print([0, 1, 3][n])
    else:
        M = [[1, 1, 1, 0],
             [1, 0, 0, 0],
             [0, 1, 0, 0],
             [1, 1, 1, 1]]
        T = [[3, 0, 0, 0],
             [2, 0, 0, 0],
             [1, 0, 0, 0],
             [6, 0, 0, 0]]
        
        ans = setup(M, n-3)
        ans = multiply(ans, T)

        print(ans[3][0])

MOD = 1000000000000007

test = int(input())
for i in range(test):
    submit()