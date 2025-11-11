def submit():
    n = int(input())
    temp = list(map(int, input().split()))

    A = dict()

    for i in temp:
        if i in A:
            A[i]+=1
        else:
            A[i] = 1
    
    maxi, now = 0, 0
    for key, val in A.items():
        if maxi < val:
            maxi = val
            now = key
    
    print(now if maxi > n//2 else "NO")


test = int(input())
for i in range(test):
    submit()
