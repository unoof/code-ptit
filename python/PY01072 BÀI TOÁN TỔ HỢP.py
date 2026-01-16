def submit():
    n, k = map(int, input().split())
    A = set(map(int, input().split()))
    
    B = sorted(list(A))

    def recursion(n, max, ans):
        if n == max:
            print(" ".join(map(str, ans)))
            return
        for i in B:
            if i > ans[len(ans)-1]:
                ans.append(i)
                recursion(n+1, max, ans)
                ans.pop()

    for i in B:
        recursion(1, k, [i])


submit()