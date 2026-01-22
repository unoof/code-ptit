def submit():
    n = int(input())
    A = dict()
    for i in range(n-1):
        key, val = map(int, input().split())
        A[key] = A.get(key, 0) + 1
        A[val] = A.get(val, 0) + 1

    check = False
    for key, val in A.items():
        if val > 1 and check == True:
            print("No")
            return
        if val > 1:
            check = True
    print("Yes")






submit()