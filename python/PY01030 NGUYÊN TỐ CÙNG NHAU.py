import math

def divisor(n)->list:
    A = []
    for i in range(2, int(math.sqrt(n))):
        if n%i == 0:
            A.append(i)
            while n%i == 0:
                n //= i
    
    if n != 1:
        A.append(n)
    return A


def submit():
    n, k = map(int, input().split())

    A = divisor(n)
    start, end = 10**(k-1), 10**k

    ans = [True for _ in range(start, end)]

    for i in A:
        current = (start//i +1)*i
        while current < end:
            ans[current-start] = False
            current+=i
    
    count = 0
    for i in range(len(ans)):
        if ans[i] is True:
            print(i+start, end=" ")
            count+=1
            if count == 10:
                print()
                count = 0




submit()