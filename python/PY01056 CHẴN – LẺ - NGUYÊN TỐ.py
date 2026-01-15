def prime_num()->list:
    prime = [True for _ in range(10001)]
    prime[0], prime[1] = False, False
    for i in range(2, 10001):
        for j in range(i*i, 10001, i):
            prime[j] = False
    return prime

def submit():
    A = list(input())

    prime = prime_num()
    total = 0
    for i in range(len(A)):
        total += int(A[i])
        if i%2 == 0 and int(A[i])%2 == 1:
            print("NO")
            return
        if i%2 == 1 and int(A[i])%2 == 0:
            print("NO")
            return
        
    print("YES" if prime[total] is True else "NO")



test = int(input())
for i in range(test):
    submit()