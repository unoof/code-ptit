def submit():
    n = int(input())
    A = dict()

    temp = list(map(int, input().split()))
    for i in temp:
        if i in A:
            A[i]+=1
        else:
            A[i] = 1
    
    temp = sorted(A.items(), key=lambda item:(-item[1], item[0]))

    for i in temp:
        for _ in range(i[1]):
            print(i[0], end=" ")

    print()


test = int(input())
for i in range(test):
    submit()
