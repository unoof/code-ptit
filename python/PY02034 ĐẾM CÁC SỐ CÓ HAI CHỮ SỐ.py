def submit():
    s = input()

    s = s[:len(s)-len(s)%2]

    A = dict()

    for i in range(0, len(s), 2):
        A[s[i:i+2]] = A.get(s[i:i+2], 0) + 1

    for key, val in A.items():
        print(key, val)







submit()