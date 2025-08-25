

def c(n, k):
    total = 1
    for i in range(1, k+1):
        total *= n-i+1
        total /= i
    return int(total)

def update(A, n, k):
    i = k-1
    while A[i] == n-k+i+1:
        i -= 1
    
    if i < 0:
        return
    
    A[i] += 1
    for j in range(i+1, k):
        A[j] = A[i]+j-i

def submit():
    n, k = map(int, input().split())
    A = set(map(int, input().split()))

    B = []
    for i in A:
        B.append(i)
    B.sort()
    C = [i for i in range(1, k+1)]
    n = len(B)
    
    for i in range(c(n, k)):
        for i in C:
            print(B[i-1], end=" ")
        print()
        update(C, n, k)

submit()