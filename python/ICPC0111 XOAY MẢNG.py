def submit():
    n, d = map(int, input().split())
    A = list(map(int, input().split()))

    A.reverse()
    A[:n-d] = A[n-d-1::-1]
    A[n-d:] = A[:n-d-1:-1]
    print(" ".join(map(str, A)))


test = int(input())
for i in range(test):
    submit()