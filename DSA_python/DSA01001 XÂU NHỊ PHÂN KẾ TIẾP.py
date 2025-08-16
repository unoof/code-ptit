def update(A):
    for i in range(len(A)-1, -1, -1):
        if A[i] == "0":
            A[i] = "1"
            break
        A[i] = "0"
    return A

def submit():
    n = list(input())
    n = update(n)
    for i in range(len(n)):
        print(n[i], end = "")
    print()

test_num = int(input())
for i in range(test_num):
    submit()