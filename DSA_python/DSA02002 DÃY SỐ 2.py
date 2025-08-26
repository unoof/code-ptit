def recursion(A, n):
    if len(A) == 1:
        return False
    
    for i in range(n-1):
        A[i] += A[i+1]
    A.pop(n-1)
    n = len(A)
    temp = list(A)

    if recursion(A, n) is False:
        print("[" + " ".join(map(str, temp)) + "]", end=" ")
        return False

def submit():
    n = int(input())
    A = list(map(int, input().split()))
    temp = list(A)

    recursion(A, n)
    print("[" + " ".join(map(str, temp)) + "]")


test = int(input())
for i in range(test):
    submit()