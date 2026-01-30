def check_krish(n):
    temp = 0
    for i in str(n):
        temp += total(int(i))
    return temp == n

def total(n):
    temp = 1
    for i in range(1, n+1):
        temp *= i
    return temp

def submit():
    n = int(input())

    print("Yes" if check_krish(n) else "No")




test = int(input())
for i in range(test):
    submit()