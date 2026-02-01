def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    A.sort()

    count = 1
    for i in range(1, n):
        if A[i] - A[i-1] > k:
            count += 1
    print(count)










submit()