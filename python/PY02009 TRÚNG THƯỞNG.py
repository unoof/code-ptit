def submit():
    n = int(input())
    A = dict()
    for i in range(n):
        temp = int(input())
        A[temp] = A.get(temp, 0) + 1

    B = []
    for key, val in A.items():
        B.append([key, val])
    B.sort(key=lambda x: (-x[1], x[0]))

    print(B[0][0])





test = int(input())
for i in range(test):
    submit()