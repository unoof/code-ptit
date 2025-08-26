def go_down(A, i, j, s):
    global found
    if i == n-1 and j == n-1:
        print(s, end=" ")
        found = True
        return

    if i+1 == n or A[i+1][j] == 0:
        return;

    s += "D"
    save = s
    i += 1
    go_down(A, i, j, s)
    go_right(A, i, j, s)

def go_right(A, i, j, s):
    if j+1 == n or A[i][j+1] == 0:
        return;

    s += "R"
    save = s
    j += 1
    go_down(A, i, j, s)
    go_right(A, i, j, s)

def submit():
    global n, found
    n = int(input())
    found = False
    A = []
    for i in range(n):
        A.append(list(map(int, input().split())))

    if A[0][0] != 0:
        i = j = 0
        s = ""
        go_down(A, i, j, s)
        go_right(A, i, j, s)
        print()
    
    if found == False:
        print(-1)
    found = False

test = int(input())
for i in range(test):
    submit()