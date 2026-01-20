def submit():
    while True:
        n = int(input())
        if n == -1:
            return
        print(n + (9-n%9)%9)








submit()