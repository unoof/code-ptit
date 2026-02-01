from math import isqrt

def check(n):
    if n < 2:
        return False

    for i in range(2, isqrt(n)+1):
        if n%i == 0:
            return False
    return True

def submit():
    n = int(input())

    A = list(map(int, input().split()))
    temp = []

    for i in A:
        if i not in temp:
            temp.append(i)

    left, right = 0, sum(temp)
    for i in range(len(temp)):
        left += temp[i]
        right -= temp[i]

        if check(left) and check(right):
            print(i)
            return
    print("NOT FOUND")








submit()