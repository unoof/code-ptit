def submit():
    A = list(map(str, input().split()))

    print(" ".join(map(str, reversed(A))))


test = int(input())
for i in range(test):
    submit()