def submit():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()

    mini = 99999999999
    for i in range(n-1):
        if mini > A[i+1] - A[i]:
            mini = A[i+1] - A[i]
    
    print(mini)


test = int(input())
for i in range(test):
    submit()
