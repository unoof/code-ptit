from bisect import bisect_right

def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    A.sort()
    check = False

    for i in range(n-2):
        temp = i+1
        j = bisect_right(A, k-A[i]-A[temp])-1
        p = k-A[i]
        while j > temp:
            if A[temp]+A[j] < p:
                temp+=1
            elif A[temp]+A[j] > p:
                j-=1
            else:
                check = True
                break
        if check == True: break
    
    print("YES" if check == True else "NO")

test = int(input())
for i in range(test):
    submit()
