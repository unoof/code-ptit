def check_num(A):
    n = len(A)
    if n%2 != 0: return False

    for i in range(n//2):
        if int(A[i])%2 != 0:
            return False
        if A[i] != A[n-i-1]:
            return False
    return True

def submit():
    n = int(input())
    if n%2 != 0:
        n+=1
    
    for i in range(22, n, 22):
        if check_num(str(i)) is True:
            print(i, end=" ")
    print()




test = int(input())
for _ in range(test):
    submit()