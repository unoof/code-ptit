def submit():
    s = input()

    s = s[:len(s)-len(s)%2]

    A = list()

    for i in range(0, len(s), 2):
        if int(s[i:i+2]) not in A:
            A.append(int(s[i:i+2]))

    print(*A)







submit()