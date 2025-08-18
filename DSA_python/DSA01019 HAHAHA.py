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
            A[i] = 'H'
            break
        A[i] = 'A'

def check(A, n):
    if (A[0] == 'A') or (A[n-1] == 'H'):
        return False
    
    alr_H = True

    for i in range(1, n-1):
        if A[i] == 'H':
            if alr_H:
                return False
            alr_H = True
        else:
            alr_H = False
    return True

def submit():
    n = int(next(it))
    A = []
    for i in range(n):
        A.append('A')

    for i in range(maximum(n)):
        if check(A, n):
            for j in A:
                print(j, end = "")
            print()
        update(A, n)


test_num = int(next(it))
for i in range(test_num):
    submit()