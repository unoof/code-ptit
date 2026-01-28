from math import prod

def total_num(n):
    temp = list(map(int, str(n)))
    return prod(temp)

def submit():
    n = int(input())
    A = list(map(int, input().split()))
    
    A.sort(key=lambda x:(total_num(x), x))

    print(*A)




test = int(input())
for i in range(test):
    submit()