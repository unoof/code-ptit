def submit():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()
    print(" ".join(map(str, A)))

test = int(input())
for i in range(test):
    submit()
