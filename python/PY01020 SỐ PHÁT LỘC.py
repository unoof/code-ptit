def submit():
    A = list(input())
    
    print("YES" if A[len(A)-1] == '6' and A[len(A)-2] == '8' else "NO")


test = int(input())
for _ in range(test):
    submit()