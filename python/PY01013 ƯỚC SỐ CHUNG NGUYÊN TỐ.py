import math

def prime_num()->list:
    prime = [True for _ in range(100001)]
    prime[0], prime[1] = False, False
    for i in range(2, 100001):
        for j in range(i*i, 100001, i):
            prime[j] = False
    return prime


def submit():
    a, b = map(int, input().split())

    n = str(math.gcd(a, b))

    prime = prime_num()

    total = 0
    for i in n:
        total += int(i)
    
    print("YES" if prime[total] is True else "NO")




test = int(input())
for _ in range(test):
    submit()