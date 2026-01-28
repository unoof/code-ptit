def submit():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    A.sort(); B.sort()

    for i in range(n-1, -1, -1):
        if B[i] < A[i]:
            print("NO")
            return
    print("YES")



test = int(input())
for i in range(test):
    submit()