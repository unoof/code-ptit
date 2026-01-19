def submit():
    A = list(input())
    
    count = 0
    while len(A) > 1:
        temp = sum(ord(c) - 48 for c in A)
        count+=1
        A = list(str(temp))

    print(count if count != 0 else 1)














submit()