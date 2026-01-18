def fibo_num()->list:
    fibo = [1, 1]
    i = 2
    while i < 94:
        fibo.append(fibo[i-1] + fibo[i-2])
        i+=1
    return fibo

def submit(fibo):
    a, b = map(int, input().split())
    
    
    print(*fibo[a-1:b])



fibo = fibo_num()
test = int(input())
for _ in range(test):
    submit(fibo)