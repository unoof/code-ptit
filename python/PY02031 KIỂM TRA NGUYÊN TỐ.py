def prime_num()->list:
    prime = [True for i in range(100001)]
    prime[0] = prime[1] = False
    for i in range(2, 100001):
        for j in range(i*i, 100001, i):
            prime[j] = False
    return prime

def submit():
    n, m = map(int, input().split())
    prime = prime_num()
    A = [list(map(int, input().split())) for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            print(1 if prime[A[i][j]] else 0, end=" ")
        print()







submit()