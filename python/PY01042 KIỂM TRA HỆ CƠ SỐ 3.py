def submit():
    A = list(input())

    temp = "012"
    for i in A:
        if i not in temp:
            print("NO")
            return
    print("YES")





test = int(input())
for i in range(test):
    submit()