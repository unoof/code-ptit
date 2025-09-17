def cmp(A):
    return A[1]

def submit():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    merge = zip(A, B)
    merge = sorted(merge, key=cmp)

    prev, count = 0, 1
    for i in range(1, n):
        if merge[i][0] >= merge[prev][1]:
            prev = i
            count += 1

    print(count)


test = int(input())
for i in range(test):
    submit()