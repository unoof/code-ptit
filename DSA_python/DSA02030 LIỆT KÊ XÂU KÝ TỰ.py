def submit():
    c, k = map(str, input().split())
    k = int(k)
    c = ord(c)

    def recursion(A, c, k, i, deep):
        if deep == len(A):
            for i in A:
                print(chr(i), end="")
            print()
        else:
            A[deep] = A[deep-1]
            while A[deep] != c+1:
                recursion(A, c, k, i, deep+1)
                A[deep] += 1

    for i in range(c-ord('A')+1):
        A = [ord('A')+i]*k
        recursion(A, c, k, i, 1)



submit()