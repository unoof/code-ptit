def submit():
    n = int(input())
    A = list(map(int, input().split()))

    def check(A, n):
        temp = [1]*n
        for i in range(1, n):
            for j in range(i):
                if A[j] < A[i]:
                    temp[i] = max(temp[i], temp[j]+1)
        return max(temp)

    print(check(A, n))



submit()