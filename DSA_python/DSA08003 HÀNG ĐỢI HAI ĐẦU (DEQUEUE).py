def submit():
    n = int(input())
    A = list()

    for i in range(n):
        s = input().split()

        if s[0] == "PUSHBACK":
            A.append(s[1])
        elif s[0] == "POPBACK":
            if len(A) != 0: A.pop()
        elif s[0] == "PUSHFRONT":
            A.insert(0, s[1])
        elif s[0] == "POPFRONT":
            if len(A) != 0: A.remove(A[0])
        elif s[0] == "PRINTBACK":
            print(A[len(A)-1] if len(A) != 0 else "NONE")
        else:
            print(A[0] if len(A) != 0 else "NONE")


submit()
