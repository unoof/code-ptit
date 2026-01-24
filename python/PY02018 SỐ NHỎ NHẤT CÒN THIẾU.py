def submit():
    n = int(input())
    A = list(map(int, input().split()))

    A.sort()

    check = False
    for i in range(A[0], A[n-1]):
        if i not in A:
            print(i)
            check = True
            return

    if not check:
        print(A[n-1]+1)










submit()