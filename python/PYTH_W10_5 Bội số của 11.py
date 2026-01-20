def submit():
    while True:
        n = int(input())
        if n == -1:
            return
        print("YES" if n%11 == 0 else "NO")








submit()