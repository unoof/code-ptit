def submit():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))

    temp = max(A)
    id = A.index(temp)
    A.insert(id, m)

    neg = [i for i in A if i < 0]
    pos = [i for i in A if i >= 0]
    ans = neg + pos

    print(*ans)


test = int(input())
for i in range(test):
    submit()