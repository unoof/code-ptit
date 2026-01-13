def submit():
    A = list(input())
    n = len(A)
    ans = ""

    count = 1
    for i in range(n-1):
        if A[i] != A[i+1]:
            ans = ans + str(count) + A[i]
            count = 1
        else:
            count+=1
    
    ans = ans + str(count) + A[n-1]

    print(ans)



test = int(input())
for _ in range(test):
    submit()