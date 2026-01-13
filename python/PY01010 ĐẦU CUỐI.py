def submit():
    A = list(input())

    print("YES" if A[0]+A[1] == A[len(A)-2] + A[len(A)-1] else "NO")



test = int(input())
for _ in range(test):
    submit()