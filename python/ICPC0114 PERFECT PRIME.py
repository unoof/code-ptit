from math import sqrt

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(sqrt(n))+1):
        if n%i == 0:
            return False
    return True

def check_rev(n):
    temp = int(str(n)[::-1])
    return is_prime(temp)

def total_num(n):
    temp = sum(list(map(int, str(n))))
    return is_prime(temp)

def check_each(n):
    A = list(map(int, str(n)))
    for i in A:
        if not is_prime(i):
            return False
    return True

def submit():
    n = int(input())
    
    if is_prime(n) and check_rev(n) and total_num(n) and check_each(n):
        print("Yes")
    else:
        print("No")




test = int(input())
for i in range(test):
    submit()