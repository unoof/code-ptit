def submit():
    n = int(input())
    A = set()

    for i in range(n):
        A.add(input().strip())

    print(len(A))




submit()