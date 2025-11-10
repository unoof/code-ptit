def submit():
    n = int(input())
    A = list(map(int, input().split()))

    mini = 1000000000
    for i in range(n-1):
        for j in range(i+1, n):
            if abs(A[i]+A[j]) < abs(mini):
                mini = A[i]+A[j]

    print(mini)



test = int(input())
for i in range(test):
    submit()
