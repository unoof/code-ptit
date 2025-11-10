def submit():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    C = A+B
    C.sort()

    print(" ".join(map(str, C)))


test = int(input())
for i in range(test):
    submit()
