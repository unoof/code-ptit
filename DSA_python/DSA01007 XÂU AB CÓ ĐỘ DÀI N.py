import sys

data = sys.stdin.read().strip().split()
it = iter(data)



def maximum(n):
    total = 1
    for i in range(n):
        total *= 2
    return int(total)

def update(A, n):
    for i in range(n-1, -1, -1):
        if A[i] == 'A':
            A[i] = 'B'
            break
        A[i] = 'A'

def submit():
    n = int(next(it))
    A = []
    for i in range(n):
        A.append('A')

    for i in range(maximum(n)):
        for j in A:
            print(j, end = "")
        print(end = " ")
        update(A, n)

    print()

test_num = int(next(it))
for i in range(test_num):
    submit()