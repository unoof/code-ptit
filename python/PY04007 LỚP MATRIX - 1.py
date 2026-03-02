class matrix:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.A = [[0]*m for _ in range(n)]

    def insert(self):
        for i in range(self.n):
            self.A[i] = list(map(int, input().split()))
    
    def rotate(self):
        C = matrix(self.m, self.n)
        for i in range(self.m):
            for j in range(self.n):
                C.A[i][j] = self.A[j][i]
        return C

def multiply(A, B):
    n, m = A.n, A.m
    p = B.m

    C = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(p):
            for k in range(m):
                C[i][j] += A.A[i][k] * B.A[k][j]
    return C

def submit():
    n, m = map(int, input().split())
    A = matrix(n, m)
    A.insert()
    B = A.rotate()
    
    C = multiply(A, B)
    for i in C:
        print(" ".join(map(str, i)))

test = int(input())
for _ in range(test):
    submit()
