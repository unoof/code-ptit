def submit():
    A = list(input())
    n = len(A)

    for i in range(1, n//2+1):
        if abs(ord(A[i])-ord(A[i-1])) != abs(ord(A[n-i])-ord(A[n-i-1])):
            print("NO")
            return
    
    print("YES")


test = int(input())
for _ in range(test):
    submit()