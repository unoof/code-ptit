import sys

data = sys.stdin.read().strip().split()
it = iter(data)

def c(k, n):
    if k > n:
        return 0
    
    total = 1
    for i in range(1, k+1):
        total *= (n-i+1)
        total /= i
    return int(total)

def submit():
    n = int(next(it))
    k = int(next(it))
    total = 1; last = 0

    for i in range(k):
        temp = int(next(it))

        for j in range(last+1, temp):
            total += c(k-i-1, n-j)
        last = temp
    
    print(total)


test_num = int(next(it))
for i in range(test_num):
    submit()