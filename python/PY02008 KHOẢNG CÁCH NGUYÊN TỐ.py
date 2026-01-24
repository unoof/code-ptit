def prime_num():
    prime = [True for i in range(100001)]
    prime[1] = prime[0] = False
    for i in range(2, 100001):
        for j in range(i*i, 100001, i):
            prime[j] = False
    return prime

def submit(prime):
    n, x = map(int, input().split())
    save = []
    i = 2
    while len(save) < n:
        if prime[i]:
            save.append(i)
        i+=1
    last = x
    print(last, end=" ")
    for i in save:
        print(last + i, end=" ")
        last += i
    print()




prime = prime_num()
submit(prime)