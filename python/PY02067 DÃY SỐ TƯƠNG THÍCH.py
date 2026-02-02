def check(n, A):
    for x in A:
        if x//n == x//(n+1):
            return False
    return True

def submit():
    n = int(input())
    A = list(map(int, input().split()))
    ans = 0

    mini = min(A)

    for k in range(mini, 0, -1):
        if check(k, A):
            for j in range(n):
                ans += A[j]//(k+1) + 1
            break
    print(ans)













submit()