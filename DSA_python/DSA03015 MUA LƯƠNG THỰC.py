import math

def submit():
    n, s, m = map(int, input().split())

    if n < m or (n-m)*6 < m:
        print(-1)
    else:
        print(math.ceil(m*s/n))

test = int(input())
for i in range(test):
    submit()