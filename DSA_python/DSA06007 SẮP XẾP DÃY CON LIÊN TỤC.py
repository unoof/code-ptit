def submit():
    n = int(input())
    A = list(map(int, input().split()))
    B = A[:]

    A.sort()
    start, end = -1, -1
    for i, j in zip(range(n), range(n-1, -1, -1)):
        if A[i] != B[i] and start == -1:
            start = i
        if A[j] != B[j] and end == -1:
            end = j
    
    print(start+1, end+1)




test = int(input())
for i in range(test):
    submit()
