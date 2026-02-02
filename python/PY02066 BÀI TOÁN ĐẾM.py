import sys

def submit():
    n = int(input())
    A = list(map(int, sys.stdin.read().split()))

    maxi = max(A)
    ans = []
    for i in range(maxi):
        if i+1 not in A:
            ans.append(i+1)

    print("\n".join(map(str, ans)) if len(ans) != 0 else "Excellent!")










submit()