def prime_num():
    prime = [True for i in range(1001)]
    prime[0] = prime[1] = False
    for i in range(2, 1001):
        for j in range(i*i, 1001, i):
            prime[j] = False
    return prime

def submit():
    n = int(input())
    A = list(map(int, input().split()))

    temp = sorted([i for i in A if prime[i]])

    j = 0
    for i in range(n):
        if prime[A[i]]:
            A[i] = temp[j]
            j+=1
    
    print(*A)



prime = prime_num()
submit()