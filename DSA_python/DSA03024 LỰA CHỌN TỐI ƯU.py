def sort_pair(A):
    return A[1]

def submit():
    n = int(input())
    A = [0]*n
    B = [0]*n

    for i in range(n):
        A[i], B[i] = map(int, input().split())

    temp = list(zip(A, B))
    temp.sort(key=sort_pair)

    prev, count = 0, 1

    for i in range(n):
        if temp[i][0] >= temp[prev][1]:
            prev = i
            count += 1

    print(count)




test = int(input())
for i in range(test):
    submit()