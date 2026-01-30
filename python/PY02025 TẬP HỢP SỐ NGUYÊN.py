def submit():
    n, m = map(int, input().split())
    A = set(map(int, input().split()))
    B = set(map(int, input().split()))
    
    C = A^B
    print(*sorted(list(A&B)))
    print(*sorted(list(C&A)))
    print(*sorted(list(C&B)))





submit()