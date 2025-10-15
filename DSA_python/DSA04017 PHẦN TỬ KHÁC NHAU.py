def submit():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    for i in range(n):
        if A[i] != B[i]:
            print(i+1)
            break
    



test = int(input())
for _ in range(test):
    submit()
