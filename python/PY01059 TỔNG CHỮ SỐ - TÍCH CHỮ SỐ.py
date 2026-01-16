def submit():
    A = list(input())

    even, odd = 0, 1
    check = False
    for i in range(len(A)):
        if i%2 == 0:
            even += int(A[i])
        else:
            if A[i] != '0':
                check = True
                odd *= int(A[i])
    
    if check == False: odd = 0
    print(even, odd)



test = int(input())
for i in range(test):
    submit()