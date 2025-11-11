def add_more(A, key, item):
    if key == item: return

    A[key].add(item)

def submit():
    v, e = map(int, input().split())
    A = dict()

    for i in range(1, v+1):
        A[i] = set()
    
    for i in range(e):
        f, s = map(int, input().split())
        add_more(A, f, s)
    
    for key, val in A.items():
        print(f"{key}:", end=" ")
        print(*sorted(val))




for i in range(int(input())):
    submit()
