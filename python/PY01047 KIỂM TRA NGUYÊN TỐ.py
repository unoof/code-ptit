def prime_num()->list:
    prime = [True for _ in range(10001)]
    prime[0], prime[1] = False, False
    for i in range(2, 10001):
        for j in range(i*i, 10001, i):
            prime[j] = False
    return prime

def submit():
    s = input()

    temp = int(s[len(s)-4:])
    prime = prime_num()
    print("YES" if prime[temp] is True else "NO")





test = int(input())
for i in range(test):
    submit()