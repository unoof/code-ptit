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

    for i in range(len(A)):
        if prime[i] and prime[int(A[i])]:
            continue
        elif prime[i] == False and prime[int(A[i])] == False:
            continue
        else:
            print("NO")
            return
    print("YES")



test = int(input())
for i in range(test):
    submit()