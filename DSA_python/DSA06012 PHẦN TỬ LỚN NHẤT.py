def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    for i in range(n-1, n-k-1, -1):
        print(A[i], end=" ")

    print()



test = int(input())
for i in range(test):
    submit()
