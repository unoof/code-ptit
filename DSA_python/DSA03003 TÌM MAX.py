def submit():
    n = int(input())
    A = list(map(int, input().split()))

    A.sort()
    total = 0

    for i in range(n):
        total += int((A[i]*i)%(1e9+7))

    print(int(total%(1e9+7)))

test = int(input())
for i in range(test):
    submit()