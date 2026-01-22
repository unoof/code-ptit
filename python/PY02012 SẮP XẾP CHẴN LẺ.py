def submit():
    n = int(input())
    A = []
    while True:
        line = list(map(int, input().split()))
        A.extend(line)
        if len(A) == n: break
    ans = []

    even = sorted([i for i in A if i%2 == 0])
    odd = sorted([i for i in A if i%2 != 0], reverse= True)

    j = k = 0
    for i in A:
        if i%2 == 0:
            ans.append(even[j])
            j+=1
        else:
            ans.append(odd[k])
            k+=1
    print(*ans)





submit()