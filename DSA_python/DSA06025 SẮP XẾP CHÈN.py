def submit():
    n = int(input())
    A = list(map(int, input().split()))
    
    ans = []
    for i in range(n):
        ans.append(A[i])
        for j in range(len(ans)):
            if ans[j] > A[i]:
                ans[j], ans[len(ans)-1] = ans[len(ans)-1], ans[j]

        print(f"Buoc {i}:", " ".join(map(str, ans)))


submit()
