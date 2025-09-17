def submit():
    n = int(input())
    A = list(map(int, input().split()))

    B = sorted(A)

    def check():
        for i in range(n):
            if A[i] != B[i] and A[i] != B[n-i-1]:
                return False
        return True
    
    print("Yes" if check() else "No")

test = int(input())
for i in range(test):
    submit()