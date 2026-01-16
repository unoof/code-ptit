def submit():
    A = list(input())

    odd, even = 0, 1
    for i in range(len(A)):
        if i%2 != 0:
            odd += int(A[i])
        else:
            if A[i] != '0':
                even *= int(A[i])
    
    print(even, odd)



test = int(input())
for i in range(test):
    submit()