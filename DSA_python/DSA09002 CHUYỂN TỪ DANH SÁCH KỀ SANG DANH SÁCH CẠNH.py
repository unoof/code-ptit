def add_more(A, key, item):
    if key == item: return

    if key > item:
        if item not in A:
            A[item] = {key}
        else:
            A[item].add(key)
    else:
        if key not in A:
            A[key] = {item}
        else:
            A[key].add(item)

def submit():
    n = int(input())
    A = dict()

    for i in range(1, n+1):
        s = map(int, input().split())
        for j in s:
            add_more(A, i, j)
    
    for key in sorted(A.keys()):
        for val in sorted(A[key]):
            print(key, val)




submit()
