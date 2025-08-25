import sys

data = sys.stdin.read().strip().split()
it = iter(data)

def reverse_list(A, start, end):
    B = []
    j = 0
    for i in range(start, end):
        B.append(A[i])
    B.reverse()
    for i in range(start, end):
        A[i] = B[j]
        j += 1
def p(n):
    total = 1
    for i in range(1, n+1):
        total *= i
    return int(total)

def update(A, n):
    i = n-2
    while i > 0 and A[i] > A[i+1]:
        i -= 1

    if i < 0:
        return
    
    k = n-1
    while A[k] < A[i]:
        k -= 1
    A[i], A[k] = A[k], A[i]
    reverse_list(A, i+1, n)

def submit():
    n = int(next(it))
    A = []
    for i in range(n):
        A.append(int(next(it)))
    A.sort()

    for i in range(p(n)):
        for i in A:
            print(i, end=" ")
        print()
        update(A, n)

submit()