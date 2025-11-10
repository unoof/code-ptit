def submit():
    k, n = map(int, input().split())
    A = [int(input()) for _ in range(n)]

    def check():
        temp = [False]*(k+1)
        temp[0] = True

        for i in range(n):
            for j in range(k, A[i]-1, -1):
                if temp[j-A[i]] == True:
                    temp[j] = True
        for i in range(k-1, -1, -1):
            if temp[i] == True:
                return i
            
    print(check())


submit()
