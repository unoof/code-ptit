def submit():
    n = int(input())

    ans = []

    def recursion(i, maxi, A):
        if i == 0:
            ans.append("(" + " ".join(map(str, A)) + ")")
            return
        
        for j in range(min(i, maxi), 0, -1):
            A.append(j)
            recursion(i-j, j, A)
            A.pop()

    recursion(n, n, [])
    print(len(ans))
    print(*ans)










test = int(input())
for i in range(test):
    submit()