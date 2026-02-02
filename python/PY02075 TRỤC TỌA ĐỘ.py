def submit():
    n = int(input())
    A = []
    B = []
    for i in range(n):
        temp = input().split()
        A.append(int(temp[0]))
        B.append(int(temp[1]))

    merge = zip(A, B)
    merge = sorted(merge, key=lambda x:(x[1]))

    prev, count = 0, 1
    for i in range(1, n):
        if merge[i][0] >= merge[prev][1]:
            prev = i
            count += 1

    print(count)






test = int(input())
for i in range(test):
    submit()