def submit():
    n = int(input())
    A = list(map(int, input().split()))

    left, right, count = 0, 0, 1
    for i in A: right += i
    left += A[count-1]; right -= A[count-1] + A[count]
    count+=1

    while left != right and count < n:
        left += A[count-1]; right -= A[count]
        count+=1
    
    print(count if left == right else -1)


test = int(input())
for i in range(test):
    submit()
