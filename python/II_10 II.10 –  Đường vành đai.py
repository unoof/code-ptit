def submit():
    m = int(input())
    v = int(input())
    t = int(input())
    d = input()

    if d == "A":
        print((-v*t)%m)
    else:
        print((v*t)%m)





submit()