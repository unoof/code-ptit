def submit():
    n = int(input())
    A = list(map(int, input().split()))
    res = []
    
    ans = []
    for i in range(n):
        ans.append(A[i])
        for j in range(len(ans)):
            if ans[j] > A[i]:
                ans[j], ans[len(ans)-1] = ans[len(ans)-1], ans[j]

        res.append(ans[:])

    for i in range(len(res)-1, -1, -1):
        print(f"Buoc {i}:", " ".join(map(str, res[i])))


submit()
