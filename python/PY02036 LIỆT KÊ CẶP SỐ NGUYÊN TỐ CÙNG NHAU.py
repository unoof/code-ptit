import math

def submit():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()

    for i in range(n-1):
        for j in range(i+1, n):
            if math.gcd(A[i], A[j]) == 1:
                print(A[i], A[j])






submit()