def submit():
    n = int(input())
    A = list()

    for i in range(n):
        s = input().split()

        if s[0] == '1':
            print(len(A))
        elif s[0] == '2':
            print("YES" if len(A) == 0 else "NO")
        elif s[0] == '3':
            A.append(s[1])
        elif s[0] == '4':
            if len(A) != 0: A.remove(A[0])
        elif s[0] == '5':
            print(-1 if len(A) == 0 else A[0])
        elif s[0] == '6':
            print(-1 if len(A) == 0 else A[len(A)-1])


test = int(input())
for i in range(test):
    submit()
