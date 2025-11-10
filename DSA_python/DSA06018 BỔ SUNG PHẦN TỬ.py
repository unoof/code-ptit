def submit():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()
    C = [False]*(A[n-1]+1)

    for i in A:
        C[i] = True

    count, start = 0, False
    for i in range(A[n-1]+1):
        if start == False and C[i] == True:
            start = True
        elif start == True and C[i] == False:
            count+=1
    print(count)


test = int(input())
for i in range(test):
    submit()
