def submit():
    s1 = f1.read()
    s2 = f2.read()
    A = set(s1.lower().split())
    B = set(s2.lower().split())
    
    C = A^B
    print(*sorted(list(C&A)))
    print(*sorted(list(C&B)))


with open("DATA1.in", 'r') as f1, open("DATA2.in", 'r') as f2:
    submit()
    f1.close(), f2.close()