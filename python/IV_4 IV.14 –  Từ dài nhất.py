def submit():
    A = list(input().split())
    A.sort(key=lambda x:-len(x))

    print(A[0], len(A[0]))







submit()