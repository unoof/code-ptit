def submit():
    n = int(input())
    A = list(map(int, input().split()))

    A.sort()
    a, b = "", ""
    for i in range(n):
        if i%2 == 0:
            a += str(A[i])
        else:
            b += str(A[i])
    print(int(a) + int(b))

test = int(input())
for i in range(test):
    submit()