import sys
data = sys.stdin.read().strip().split()
it = iter(data)

def submit():
    n = int(next(it))
    count, check = 1, False
    A = [0]*n
    A[0] = int(next(it))

    for i in range(1, n):
        A[i] = int(next(it))
        if A[i] >= A[i-1] and check == False:
            count+=1
        else:
            check = True
    
    print(count if check == True else 0)


test = int(next(it))
for i in range(test):
    submit()
