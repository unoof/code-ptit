def recursion(A, n, k, start, total, ans):
    global found
    for i in range(start, n):
        total += A[i]
        save = ans[:]
        ans.append(A[i])
        if total > k:
            total -= A[i]
            return
        if total == k:
            print("[" + " ".join(map(str, ans)) + "]", end=" ")
            found = True
            total -= A[i]
            return
        
        recursion(A, n, k, i+1, total, ans)
        total -= A[i]
        ans = save[:]

def submit():
    global found
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()
    ans = []

    found = False
    recursion(A, n, k, 0, 0, ans)
    if found == False:
        print(-1)
    else:
        print()


test = int(input())
for i in range(test):
    submit()