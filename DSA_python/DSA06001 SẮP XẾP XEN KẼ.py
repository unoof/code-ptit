def submit():
    n = int(input())
    A = list(map(int, input().split()))

    A.sort()

    left, right = 0, n-1
    while left <= right:
        if left == right: print(A[left], end='')
        else: print(f"{A[right]} {A[left]}", end=" ")
        left+=1
        right-=1
    
    print()


test = int(input())
for _ in range(test):
    submit()