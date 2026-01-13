def submit():
    temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."
    while True:
        A = list(input())
        if A[0] == '0':
            break
        total = ""
        B = list()
        for i in A:
            if i.isdigit():
                total = total + i
            elif i.isspace() is False:
                B.append(i)
        total = int(total)

        for i in range(len(B)):
            B[i] = temp[(temp.find(B[i]) + total)%28]

        print("".join(map(str, reversed(B))))




submit()