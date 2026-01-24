def submit():
    while True:
        A = list(map(int, input().split()))
        if A[0] == A[1] == A[2] == A[3] == 0: return

        count = 0
        while len(set(A)) != 1:
            A = [abs(A[i] - A[(i+1) % 4]) for i in range(4)]
            count+=1
        print(count)





submit()