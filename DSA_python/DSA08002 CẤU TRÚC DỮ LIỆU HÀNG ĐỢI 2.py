def submit():
    n = int(input())
    A = list()

    for i in range(n):
        s = input().split()

        if s[0] == "PUSH":
            A.append(s[1])
        elif s[0] == "POP":
            if len(A) != 0: A.remove(A[0])
        else:
            print(A[0] if len(A) != 0 else "NONE")


submit()
