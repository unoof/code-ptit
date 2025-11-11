def submit():
    s = input()
    A = list(s)
    check = False

    for i in range(len(s)):
        if ord(s[i]) - ord('0') > 1 or check == True:
            A[i] = "1"
            check = True
    
    def to_int(A):
        n = 0
        for i in A:
            n = n*2
            if i == '1':
                n+=1
        return n
    
    print(to_int(A))





for i in range(int(input())):
    submit()
