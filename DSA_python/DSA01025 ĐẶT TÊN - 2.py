import sys

data = sys.stdin.read().strip().split()
it = iter(data)

def c(n, k):
    total = 1
    for i in range(1, k+1):
        total *= (n-i+1)
        total /= i
    return int(total)

def update(A, n, k):
    i = k-1
    while A[i] == n-k+i+1:
        i -= 1
    if i == -1:
        return

    A[i] += 1
    for j in range(i+1, k):
        A[j] = A[i]+j-i

    return A

def submit():
    n = int(next(it))
    k = int(next(it))
    A = []
    for i in range(1, k+1):
        A.append(i)

    for i in range(c(n,k)):
        for j in A:
            print(chr(j + ord('A') -1), end= "")
        print()
        A = update(A, n, k)

    print()

test_num = int(next(it))
for i in range(test_num):
    submit()