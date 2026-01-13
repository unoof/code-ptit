def submit():
    A = list(input())
    ans = ""
    for i in range(1, len(A)):
        if A[i].isdigit():
            ans = ans + A[i-1]*int(A[i])
    
    print(ans)




test = int(input())
for _ in range(test):
    submit()