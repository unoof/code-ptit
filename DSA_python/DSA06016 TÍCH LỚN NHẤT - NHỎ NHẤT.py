def submit():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    print(max(A)*min(B))


test = int(input())
for i in range(test):
    submit()
