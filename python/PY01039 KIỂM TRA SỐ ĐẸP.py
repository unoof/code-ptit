def submit():
    A = list(input())

    first, second = A[0], A[1]
    for i in range(2, len(A)-1, 2):
        if A[i] != first or A[i+1] != second:
            print("NO")
            return
    print("YES")





test = int(input())
for i in range(test):
    submit()