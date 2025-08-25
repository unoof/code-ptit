import sys

data = sys.stdin.read().strip().split()
it = iter(data)

def c(k, n):
    if k > n:
        return 0
    
    total = 1
    for i in range(1, k+1):
        total *= (n-i+1)
        total /= i
    return int(total)

def reverse_list(A, start, end):
    B = []
    for i in range(start, end):
        B.append(A[i])

    B.reverse()
    j = 0
    for i in range(start, end):
        A[i] = B[j]
        j += 1

def update(A, n):
    i = n-2
    while A[i] >= A[i+1] and i >= 0:
        i -= 1
    if i < 0:
        return
    
    k = n-1
    while A[i] >= A[k]:
        k -= 1
    A[i], A[k] = A[k], A[i]
    A = reverse_list(A, i+1, n)
    return A

def submit():
    n = int(next(it))
    k = int(next(it))
    A = []

    for i in range(k, n):
        A.append(0)

    for i in range(k):
        A.append(1)

    for i in range(c(k, n)):
        for j in A:
            print(j, end="")
        print()
        update(A, n)


test_num = int(next(it))
for i in range(test_num):
    submit()