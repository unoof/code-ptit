import sys

def submit():
    A = list(map(int, sys.stdin.read().split()))
    B = set()

    for i in A:
        B.add(i%42)
    print(len(B))





submit()