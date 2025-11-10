def submit():
    n = int(input())
    A = list(map(int, input().split()))

    for i in range(n-1):
        for j in range(i+1, n):
            if A[i]>A[j]:
                A[i], A[j] = A[j], A[i]
        print(f"Buoc {i+1}:", end=" ")
        print(" ".join(map(str, A)))


submit()
