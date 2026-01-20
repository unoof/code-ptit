def submit():
    while True:
        A = list(map(int, input().split()))
        if A[0] == -1:
            return
        y, z = A[0], A[1]

        total = 0
        for i in str(y):
            total += int(i)
        print(z//total)








submit()