import sys

class matrix:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.A = [[0]*m for _ in range(n)]

    def insert(self, input):
        global i
        for j in range(self.n):
            self.A[j] = list(input[i: i+self.m])
            i += self.m
    
    def rotate(self):
        C = matrix(self.m, self.n)
        for i in range(self.m):
            for j in range(self.n):
                C.A[i][j] = self.A[j][i]
        return C

def multiply(A, B):
    n, m = A.n, A.m
    p = B.m

    C = [[0]*p for _ in range(n)]
    for i in range(n):
        for j in range(p):
            for k in range(m):
                C[i][j] += A.A[i][k] * B.A[k][j]
    return C

def submit(input):
    global i
    n, m = int(input[i]), int(input[i+1])
    i += 2
    A = matrix(n, m)
    A.insert(input)
    B = A.rotate()
    
    C = multiply(A, B)
    for j in C:
        print(" ".join(map(str, j)))

i = 1
input = list(map(int, sys.stdin.read().split()))
for _ in range(int(input[0])):
    submit(input)