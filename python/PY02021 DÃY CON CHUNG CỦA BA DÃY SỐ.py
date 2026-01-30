def submit():
    n, m, p = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    ans = []

    i, j, k = 0, 0, 0
    while i < n and j < m and k < p:
        if A[i] == B[j] and B[j] == C[k]:
            ans.append(A[i])
            i+=1; j+=1; k+=1
        elif A[i] < B[j]:
            i+=1
        elif B[j] < C[k]:
            j+=1
        else:
            k +=1
    
    print(" ".join(map(str, ans)) if len(ans) else "NO")


test = int(input())
for _ in range(test):
    submit()