def submit():
    n = int(input())
    A = ["6", "8"]
    res = []

    while len(A[0]) <= n:
        temp = A[0]
        res.append(A[0])
        A.remove(A[0])
        A.append(temp+"6"); A.append(temp+"8")
    
    print(len(res))
    print(*reversed(res))




for i in range(int(input())):
    submit()
