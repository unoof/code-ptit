import sys

data = sys.stdin.read().strip().split()
it = iter(data)

def update(A, i, start):
    for j in range(start, len(A)):
        t[i] = A[j]
        if i == k-1:
            for x in t:
                print(x, end=" ")
            print()
        else:
            update(A, i+1, j+1)

def submit():
    global k, t
    n = int(next(it))
    k = int(next(it))
    A = {next(it) for _ in range(n)}

    B = sorted(A)
    t = [""]*k

    update(B, 0, 0)


t = []
k = 0
submit()