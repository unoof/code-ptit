def submit():
    while True:
        n = int(input())
        if n == 0: return
        count = 1
        while n != 1:
            if n&1:
                n = n*3+1
            else:
                n //= 2
            count+=1
        print(count)






submit()