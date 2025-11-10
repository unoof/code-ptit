def prepare():
    prime = [True]*(10**6+1)
    prime[0] = prime[1] = False
    for i in range(2, 10**6+1):
        for j in range(i*i, 10**6+1, i):
            prime[j] = False
    return prime

def submit():
    n = int(input())
    check = False
    for i in range(n):
        if prime[n-i] == True and prime[i] == True:
            check = True
            print(i, n-i)
            break
    
    if check == False: print(-1)


test = int(input())
prime = prepare()
for i in range(test):
    submit()
