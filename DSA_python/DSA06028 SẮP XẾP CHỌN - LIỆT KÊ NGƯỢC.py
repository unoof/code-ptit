def submit():
    n = int(input())
    A = list(map(int, input().split()))
    res = []
    
    for i in range(n-1):
        mini = i
        for j in range(i+1, n):
            if A[j] < A[mini]:
                mini = j
        A[mini], A[i] = A[i], A[mini]

        res.append(A[:])

    for i in range(len(res)-1, -1, -1):
        print(f"Buoc {i+1}:", " ".join(map(str, res[i])))


submit()
