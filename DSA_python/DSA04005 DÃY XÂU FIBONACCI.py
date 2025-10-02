def submit():
    n, k = map(int, input().split())
    A = [0]*(n+1)
    A[1] = A[2] = 1
    count = 3

    for i in range(3, n+1):
        A[i] = A[i-2] + A[i-1]
        count += 1
        if A[i] >= k: break

    def kthchar(n, k):
        if n == 1: return "A"
        if n == 2: return "B"

        if k <= A[n-2]:
            return kthchar(n-2, k)
        else:
            return kthchar(n-1, k - A[n-2])
        
    print(kthchar(count, k))

test = int(input())
for _ in range(test):
    submit()
