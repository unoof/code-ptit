def submit():
    s = input()

    for i in range(1000):
        if int(s)%7 == 0:
            print(s)
            return
        s = str(int(s) + int(s[::-1]))
    print(-1)



test = int(input())
for i in range(test):
    submit()