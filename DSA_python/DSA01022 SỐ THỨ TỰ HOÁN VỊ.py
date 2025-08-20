import sys

data = sys.stdin.read().strip().split()
it = iter(data)

def factorial(n):
    total = 1
    for i in range(1, n+1):
        total *= i
    return total

def check(A, n):
    count = 0
    for i in range(0, n):
        if A[i] == False:
            count += 1
    return count

def submit():
    n = int(next(it))
    total = 1
    A = []
    for i in range(n):
        A.append(True)

    for i in range(n):
        temp = int(next(it))

        total += factorial(n-i-1)*(temp-1-check(A, temp))
        A[temp-1] = False
    
    print(total)


test_num = int(next(it))
for i in range(test_num):
    submit()