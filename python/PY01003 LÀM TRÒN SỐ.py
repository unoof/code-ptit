def submit():
    s = list(input())
    n = len(s)

    for i in range(n-1, 0, -1):
        if int(s[i]) >= 5:
            s[i] = "0"
            s[i-1] = str(int(s[i-1])+1)
        else:
            s[i] = "0"
    
    print("".join(map(str, s)))


test = int(input())
for _ in range(test):
    submit()