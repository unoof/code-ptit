def submit():
    A = list(input())

    if A[0] == A[1] or len(A)%2 == 0:
        print("NO")
        return

    for i in range(len(A), 2):
        if i != A[0]:
            print("NO")
            return
    print("YES")



test = int(input())
for i in range(test):
    submit()