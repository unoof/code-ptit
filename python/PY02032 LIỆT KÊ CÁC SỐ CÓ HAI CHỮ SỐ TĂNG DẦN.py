def submit():
    s = input()

    s = s[:len(s)-len(s)%2]

    A = set()

    for i in range(0, len(s), 2):
        A.add(int(s[i:i+2]))

    print(*(sorted(list(A))))







submit()