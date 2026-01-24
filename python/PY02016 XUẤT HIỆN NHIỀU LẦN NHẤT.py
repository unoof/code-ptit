def submit():
    n = int(input())
    temp = list(map(int, input().split()))

    A = dict()

    for i in temp:
        A[i] = A.get(i, 0) + 1
    
    maxi, now = 0, 0
    for key, val in A.items():
        if maxi < val:
            maxi = val
            now = key
    
    print(now if maxi > n//2 else "NO")









test = int(input())
for i in range(test):
    submit()