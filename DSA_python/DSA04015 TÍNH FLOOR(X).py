def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    def upper_bound(target):
        for i in range(n):
            if A[i] > target:
                return i
        return n

    if k < A[0]: print(-1)
    else:
        print(upper_bound(k))


    

test = int(input())
for _ in range(test):
    submit()
