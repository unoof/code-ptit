def submit():
    n = int(input())
    A = set(map(int, input().split()))

    B = list(sorted(A))

    if len(B) == 1:
        print(-1)
    else:
        print(B[0], B[1])



test = int(input())
for i in range(test):
    submit()
