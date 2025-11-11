def submit():
    n = int(input())
    A = list()

    for i in range(n):
        s = input().split()

        if s[0] == "PUSH":
            A.append(s[1])
        elif s[0] == "POP":
            if (len(A) != 0): A.pop()
        else:
            if len(A) != 0:
                print(A[len(A)-1])
            else:
                print("NONE")



submit()
