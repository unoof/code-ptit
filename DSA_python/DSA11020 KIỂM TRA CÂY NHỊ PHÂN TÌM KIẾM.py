def submit():
    n = int(input())
    edges = list(map(int, input().split()))

    check = True

    for i in range(n-1):
        if edges[i] >= edges[i+1]:
            check = False
            break
    
    print(1 if check == True else 0)











test = int(input())
for i in range(test):
    submit()