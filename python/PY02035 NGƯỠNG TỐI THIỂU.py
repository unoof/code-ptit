def submit():
    s = input()
    k = int(input())

    s = s[:len(s)-len(s)%2]

    A = dict()

    for i in range(0, len(s), 2):
        A[s[i:i+2]] = A.get(s[i:i+2], 0) + 1

    A = dict(sorted(A.items(), key=lambda x:(x[0])))

    check = False
    for key, val in A.items():
        if val >= k:
            print(key, val)
            check = True

    if not check:
        print("NOT FOUND")






submit()