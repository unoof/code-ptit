import sys, math

def convention(n):
    temp = []

    for i in range(2, math.isqrt(n)+1):
        if n%i == 0:
            temp.append(i)
    return temp

def magic(n, A):
    count = 0
    for i in A:
        num = n//i - (i-1)
        if num%2 == 0:
            count += 1
    return count

def submit():
    n = int(sys.stdin.readline().strip())

    print(magic(n*2, convention(n*2)))






test = int(sys.stdin.readline())
for _ in range(test):
    submit()