def prime_num():
    prime = [True for i in range(1000001)]
    prime[0] = prime[1] = False
    for i in range(2, 1000001):
        for j in range(i*i, 1000001, i):
            prime[j] = False
    return prime

def submit(prime):
    n = int(input())
    A = list(map(int, input().split()))
    save = dict()
    for i in A:
        if i > 0 and prime[i]:
            save[i] = save.get(i, 0) + 1
    
    for key, val in save.items():
        print(key, val)



prime = prime_num()
submit(prime)