def submit():
    n = int(input())
    A = list(map(int, input().split()))

    def BS_index(A, left, right, target):
        mid = left + (right - left)/2
        mid = int(mid)
        if A[mid] == 0 and A[mid+1] == 0:
            return BS_index(A, mid, right, target)
        elif A[mid] == 1 and A[mid-1] == 1:
            return BS_index(A, left, mid-1, target)
        else:
            if A[mid] == 0 and A[mid+1] == 1:
                return mid+1
            else:
                return mid

    if A[n-1] != 1:
        print(n)
    elif A[0] == 1:
        print(0)
    else:
        print(BS_index(A, 0, n-1, 1))



test = int(input())
for _ in range(test):
    submit()
