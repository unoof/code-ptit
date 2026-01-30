def submit():
    n, m = map(int, input().split())
    A = list(set(map(int, input().split())))
    B = list(set(map(int, input().split())))
    
    if len(A) != len(B):
        print("NO")
        return
    for i in range(len(A)):
        if A[i] != B[i]:
            print("NO")
            return
    print("YES")





submit()