import sys

def submit():
    n = int(sys.stdin.readline())
    A = []
    for i in range(n):
        A.append(int(sys.stdin.readline()))
    A.sort(reverse=True)
    print(f"Silver = {A[1]}")






submit()