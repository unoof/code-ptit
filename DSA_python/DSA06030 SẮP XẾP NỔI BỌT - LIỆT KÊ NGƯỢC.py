def submit():
    n = int(input())
    A = list(map(int, input().split()))
    res = []
    
    for i in range(n):
        check = False
        for j in range(n-1):
            if A[j] > A[j+1]:
                A[j], A[j+1] = A[j+1], A[j]
                check = True
        if check == False:
            break

        res.append(A[:])
    
    for i in range(len(res)-1, -1, -1):
        print(f"Buoc {i+1}:", " ".join(map(str, res[i])))

test = int(input())
for i in range(test):
    submit()
