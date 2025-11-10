def submit():
    n = int(input())
    A = list(map(int, input().split()))

    count, maxi = 1, -1
    down, up = False, False
    for i in range(n-1):
        if A[i] < A[i+1]:
            if down == True:
                maxi = max(count, maxi)
                count = 2
                down = False
            else:
                count+=1
                up = True
        elif A[i] > A[i+1] and up == True:
            count+=1
            down = True
        elif A[i] == A[i+1]:
            maxi = max(maxi, count)
            count = 1
            up = down = False
    

    print(max(maxi, count))
    

test = int(input())
for i in range(test):
    submit()
