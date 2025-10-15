def submit():
    n, k = map(int, input().split())
    A = [1]*(n+1)
    count = 3

    for i in range(3, n+1):
        A[i] = A[i-2] + A[i-1]
        count+=1
        if A[i] >= k:
            break

    def kthChar(A, n, k):
        if n == 1: return 0
        if n == 2: return 1

        if k <= A[n-2]:
            return kthChar(A, n-2, k)
        else:
            return kthChar(A, n-1, k - A[n-2])
        
    print(kthChar(A, count, k))



test = int(input())
for _ in range(test):
    submit()
