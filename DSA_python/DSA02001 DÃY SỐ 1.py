def recursion(A, n):
    if len(A) == 1:
        return
    
    for i in range(n-1):
        A[i] += A[i+1]
    A.pop(n-1)
    n = len(A)

    print("[" + " ".join(map(str, A)) + "]")
    recursion(A, n)

def submit():
    n = int(input())
    A = list(map(int, input().split()))

    print("[" + " ".join(map(str, A)) + "]")
    recursion(A, n)


test = int(input())
for i in range(test):
    submit()