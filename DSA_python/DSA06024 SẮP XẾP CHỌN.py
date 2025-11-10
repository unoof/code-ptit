def submit():
    n = int(input())
    A = list(map(int, input().split()))
    
    for i in range(n-1):
        mini = i
        for j in range(i+1, n):
            if A[j] < A[mini]:
                mini = j
        A[mini], A[i] = A[i], A[mini]

        print(f"Buoc {i+1}:", " ".join(map(str, A)))


submit()
