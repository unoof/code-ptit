def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    print(1 if k in A else -1)


test = int(input())
for i in range(test):
    submit()
