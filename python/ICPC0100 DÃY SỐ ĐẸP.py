def fix(small, big):
    count = 0
    while small*2 < big:
        small *= 2
        count+=1
    return count

def submit():
    n = int(input())
    A = list(map(int, input().split()))

    count = 0
    for i in range(n-1):
        if max(A[i], A[i+1]) > 2*min(A[i], A[i+1]):
            count += fix(min(A[i], A[i+1]), max(A[i], A[i+1]))
    print(count)



test = int(input())
for i in range(test):
    submit()