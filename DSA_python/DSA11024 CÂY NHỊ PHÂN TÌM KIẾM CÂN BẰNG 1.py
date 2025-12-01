def submit():
    n = int(input())
    edges = list(map(int, input().split()))

    edges.sort()

    print(edges[(n-1)>>1])











test = int(input())
for i in range(test):
    submit()