def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    
    def check():
        temp = [False]*(k+1)
        temp[0] = True

        for i in range(n):
            for j in range(k, A[i]-1, -1):
                if temp[j-A[i]] == True:
                    temp[j] = True
        return temp[k]
    
    print("YES" if check() == True else "NO")

test = int(input())
for _ in range(test):
    submit()
