def next(A, n):
    for i in range(n-1, -1, -1):
        if A[i] == 'A':
            A[i] = 'B'
            break
        A[i] = 'A'

def maximum(n):
    total = 1
    for i in range(1, n+1):
        total *= 2
    return total

def submit():
    n, k = map(int, input().split())
    A = ['A']*n
    ans = list()

    for i in range(maximum(n)):
        check = False
        count = 0
        for j in A:
            if j == 'A':
                count+=1
                check = True
            elif j == 'B' and check == True:
                if count == k:
                    break
                else:
                    count = 0
                    check = False
            
        if count == k:
            ans.append(A[:])
        next(A, n)
    
    print(len(ans))
    for i in ans:
        print("".join(map(str, i)))



submit()