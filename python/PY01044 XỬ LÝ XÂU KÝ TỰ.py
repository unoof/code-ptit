def submit():
    s1 = input().lower()
    s2 = input().lower()
    A = list(s1.split())
    B = list(s2.split())

    common = set(A)&set(B)
    common = sorted(list(common))
    A.extend(B)
    A = sorted(list(set(A)))

    print(*A)
    print(*common)







submit()