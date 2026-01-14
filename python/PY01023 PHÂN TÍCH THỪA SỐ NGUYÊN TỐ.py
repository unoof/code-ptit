import math

def submit():
    n = int(input())
    ans = "1"

    count = 0
    for i in range(2, int(math.sqrt(n))):
        if n%i == 0:
            ans += " * "
            while n%i == 0:
                n //= i
                count+=1
            ans += f"{i}^{count}"
            count = 0
    
    if n != 1:  
        ans += f" * {n}^1"
    print(ans)


test = int(input())
for _ in range(test):
    submit()