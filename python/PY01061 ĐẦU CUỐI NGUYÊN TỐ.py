def prime_num()->list:
    prime = [True for _ in range(10001)]
    prime[0], prime[1] = False, False
    for i in range(2, 10001):
        for j in range(i*i, 10001, i):
            prime[j] = False
    return prime

def submit():
    A = input()
    prime = prime_num()

    print("YES" if prime[int(A[len(A)-3:])] and prime[int(A[:3])] else "NO")



test = int(input())
for i in range(test):
    submit()