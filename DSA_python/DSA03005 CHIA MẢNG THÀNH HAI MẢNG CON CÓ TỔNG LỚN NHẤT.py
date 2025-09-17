def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    A.sort()
    first, second = 0, 0
    k = min(k, n-k)

    for i in range(n):
        if i < k:
            first += A[i]
        else:
            second += A[i]

    print(second-first)

test = int(input())
for i in range(test):
    submit()