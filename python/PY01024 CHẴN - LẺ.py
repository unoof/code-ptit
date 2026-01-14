def submit():
    A = list(input())
    total = 0
    for i in range(len(A)):
        A[i] = int(A[i])
        total += A[i]
    
    for i in range(1, len(A)):
        if abs(A[i] - A[i-1]) != 2:
            print("NO")
            return
    
    print("YES" if total%10 == 0 else "NO")

test = int(input())
for _ in range(test):
    submit()