def submit():
    s = input()
    check = True
    for i in s:
        if i != "4" and i != "7":
            check = False
    
    print("YES" if check is True else "NO")



test = int(input())
for _ in range(test):
    submit()