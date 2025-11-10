def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    ans = []

    start, end, maxi = 1, k, -1

    for i in range(end):
        maxi = max(maxi, A[i])
    ans.append(maxi)

    while end < n:
        if A[start-1] == maxi:
            maxi = -1
            for i in range(start, end+1):
                maxi = max(maxi, A[i])
        else:
            maxi = max(maxi, A[end])
        
        ans.append(maxi)
        start+=1; end+=1
    
    print(" ".join(map(str, ans)))

test = int(input())
for i in range(test):
    submit()
