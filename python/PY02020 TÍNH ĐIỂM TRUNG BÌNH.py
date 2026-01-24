def submit():
    n = int(input())
    A = list(map(float, input().split()))

    A.sort()
    mini, maxi = A[0], A[n-1]
    ans = []
    total = 0
    for i in range(n):
        if A[i] != mini and A[i] != maxi:
            ans.append(A[i])
    total = sum(ans)
    print(f"{total/len(ans):.3}")








submit()