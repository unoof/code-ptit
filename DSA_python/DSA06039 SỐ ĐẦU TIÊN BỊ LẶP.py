def submit():
    n = int(input())
    A = list(map(int, input().split()))

    check = set()
    ans = n
    for i in range(n-1, -1, -1):
        if A[i] in check:
            if ans > i: ans = i
        check.add(A[i])
    
    print(A[ans] if ans != n else "NO")

test = int(input())
for i in range(test):
    submit()
