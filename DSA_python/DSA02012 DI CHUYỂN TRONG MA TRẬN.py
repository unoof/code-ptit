def go_down(A, i, j):
    global count
    if i == n-1 and j == m-1:
        count += 1
        return

    if i+1 == n:
        return

    i += 1
    go_down(A, i, j)
    go_right(A, i, j)

def go_right(A, i, j):
    if j+1 == m:
        return

    j += 1
    go_down(A, i, j)
    go_right(A, i, j)

def submit():
    global n, m, count
    n, m = map(int, input().split())
    A = []
    for i in range(n):
        A.append(list(map(int, input().split())))

    count = 0
    go_down(A, 0, 0)
    go_right(A, 0, 0)
    print(count)

test = int(input())
for i in range(test):
    submit()