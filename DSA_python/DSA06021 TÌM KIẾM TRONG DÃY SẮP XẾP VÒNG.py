import sys

data = sys.stdin.read().strip().split()
it = iter(data)

def submit():
    n = int(next(it))
    k = int(next(it))
    for i in range(n):
        temp = int(next(it))
        if temp == k:
            print(i+1)



test = int(next(it))
for i in range(test):
    submit()
