def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    C = [False]*(max(A[n-1]+1, B[k-1]+1))
    D = [False]*(max(A[n-1]+1, B[k-1]+1))

    for i in A:
        C[i] = True
    for i in B:
        D[i] = True
    
    for i in range(len(C)):
        if C[i] or D[i] == True:
            print(i, end=" ")
    print()
    for i in range(len(C)):
        if C[i] and D[i] == True:
            print(i, end=" ")
    print()

test = int(input())
for i in range(test):
    submit()
