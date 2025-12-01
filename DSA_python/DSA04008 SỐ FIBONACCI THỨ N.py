def multiply(A, B):
    C = [[0, 0],
         [0, 0]]
    
    for i in range(2):
        for j in range(2):
            for k in range(2):
                C[i][j] += (A[i][k]*B[k][j])%MOD
    
    return C

def setup(A, n):
    ans = [[1, 0],
           [0, 1]]
    
    while n > 0:
        if n&1:
            ans = multiply(ans, A)
        A = multiply(A, A)
        n >>= 1

    return ans


def submit():
    n = int(input())

    M = [[1, 1],
         [1, 0]]
    T = [[1, 0],
         [0, 0]]
    
    ans = setup(M, n-1)
    ans = multiply(ans, T)

    print(ans[0][0])


MOD = 1000000007

test = int(input())
for i in range(test):
    submit()