import sys

data = sys.stdin.read().strip().split()
it = iter(data)

def change(A, n):
    if A[n]:
        A[n] = False
        return
    A[n] = True

def update(A, n, k):
    i = k
    j = n-1
    while j > 0:
        if A[j]:
            if j+1 == n-k+i:
                i -= 1
            else:
                break
        j -= 1
    
    if i != 0:
        A[j] = False
        change(A, j+1)
        for x in range(j+2, j+2+k-i):
            change(A, x)
        for x in range(j+2+k-i, n):
            A[x] = False
        for x in range(j+1):
            A[x] = False

def submit():
    n = int(next(it))
    k = int(next(it))
    count = 0
    A = []

    for i in range(n):
        A.append(False)

    for i in range(k):
        temp = int(next(it))
        A[temp-1] = True

    update(A, n, k)
    for j in A:
        if j:
            count += 1
    print(count)


test_num = int(next(it))
for i in range(test_num):
    submit()