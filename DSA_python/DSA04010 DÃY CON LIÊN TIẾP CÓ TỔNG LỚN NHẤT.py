def submit():
    n = int(input())
    max, stored = -101, 0
    A = list(map(int, input().split()))

    for i in A:
        stored += i
        if stored < i: stored = i
        if stored > max: max = stored

    print(max)

test = int(input())
for _ in range(test):
    submit()
