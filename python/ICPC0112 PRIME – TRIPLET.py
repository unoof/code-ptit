def prime_num():
    prime = [True for i in range(100001)]
    prime[0], prime[1] = False, False
    for i in range(2, 100001):
        for j in range(i*i, 100001, i):
            prime[j] = False
    return prime

def submit(prime):
    n = int(input())

    count = 0
    for i in range(n-6):
        if prime[i] and prime[i+6]:
            if prime[i+2] or prime[i+4]:
                count+=1
    print(count)


prime = prime_num()
test = int(input())
for i in range(test):
    submit(prime)