def submit():
    n = int(input())
    A = [9]
    res = 9

    while res%n != 0:
        res = A[0]
        A.remove(A[0])
        A.append(res*10); A.append(res*10 + 9)
    
    print(res)


for i in range(int(input())):
    submit()
