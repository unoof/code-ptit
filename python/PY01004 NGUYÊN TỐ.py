import math

def prime_num()->list:
    prime = [True for _ in range(10001)]
    prime[0], prime[1] = False, False
    for i in range(2, 10001):
        for j in range(i*i, 10001, i):
            prime[j] = False

    return prime

def submit():
    n = int(input())
    prime = prime_num()
    count = 0

    for i in range(1, n):
        if math.gcd(i, n) == 1:
            count+=1
    
    print("YES" if prime[count] is True else "NO")




test = int(input())
for _ in range(test):
    submit()