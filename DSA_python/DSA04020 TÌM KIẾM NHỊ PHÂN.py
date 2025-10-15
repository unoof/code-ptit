def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    def BS_index(A, left, right, target):
        if left > right:
            return "NO"

        mid = left + (right - left)/2
        mid = int(mid)
        if A[mid] < target:
            return BS_index(A, mid+1, right, target)
        elif A[mid] > target:
            return BS_index(A, left, mid-1, target)
        else:
            return mid+1


    print(BS_index(A, 0, n-1, k))



test = int(input())
for _ in range(test):
    submit()
