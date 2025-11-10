def submit():
    n = int(input())
    A = list(map(int, input().split()))
    
    for i in range(n):
        check = False
        for j in range(n-1):
            if A[j] > A[j+1]:
                A[j], A[j+1] = A[j+1], A[j]
                check = True
        if check == False:
            break

        print(f"Buoc {i+1}:", " ".join(map(str, A)))


submit()
