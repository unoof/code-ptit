def submit():
    n, k = map(int, input().split())
    A = set(map(str, input().split()))
    B = list(sorted(A))
    t = [[] for _ in range(k)]

    def update(A, i, start):
        for j in range(start, len(A)):
            t[i] = A[j]
            if i == k-1:
                print(" ".join(t))
            else:
                update(A, i+1, j+1)

    update(B, 0, 0)


submit()