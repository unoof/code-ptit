def submit():
    A = list(input().split('.'))

    if len(A) != 4:
        print("NO")
        return

    for i in A:
        if i.isalpha() or int(i) > 255 or int(i) < 0:
            print("NO")
            return
    print("YES")




test = int(input())
for i in range(test):
    submit()