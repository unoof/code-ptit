def submit():
    A = list(input())

    check = True
    for i in range(len(A)-1):
        if A[i] > A[i+1]:
            check = False
            break
    
    print("YES" if check == True else "NO")



test = int(input())
for _ in range(test):
    submit()