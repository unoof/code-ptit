def prime_num()->list:
    prime = [True for _ in range(10001)]
    prime[0], prime[1] = False, False
    for i in range(2, 10001):
        for j in range(i*i, 10001, i):
            prime[j] = False
    return prime

def submit():
    s = input()
    prime = prime_num()

    if prime[len(s)] is False:
        print("NO")
        return
    
    count = 0
    for i in s:
        if prime[int(i)] is True:
            count += 1
        else:
            count -= 1

    print("YES" if count > 0 else "NO")





test = int(input())
for i in range(test):
    submit()