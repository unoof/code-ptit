def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    A.sort()
    count, j = 0, 0
    for i in range(n):
        while j < n and A[j] - A[i] < k:
            j+=1
        count += j-i-1
    
    print(count)


test = int(input())
for i in range(test):
    submit()
