def submit():
    n = int(input())
    A = ["1"]
    ans = []

    for i in range(n):
        temp = A[0]
        A.remove(A[0])
        ans.append(temp)
        A.append(temp+"0"); A.append(temp+"1")
    
    print(*ans)


for i in range(int(input())):
    submit()
