def submit():
    n, m, p = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    i, j, k = 0, 0, 0
    ans = list()
    check = False

    while i< n and j < m and k < p:
        if A[i] == B[j] == C[k]:
            check = True
            ans.append(A[i])
            i+=1; j+=1; k+=1
        elif A[i] < B[j]:
            i+=1
        elif B[j] < C[k]:
            j+=1
        else:
            k+=1
    
    if check == True:
        print(" ".join(map(str, ans)))
    else:
        print(-1)

test = int(input())
for i in range(test):
    submit()
