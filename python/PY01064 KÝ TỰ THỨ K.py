def submit():
    n, k = map(int, input().split())
    
    count = 0
    while not k&1:
        k >>= 1
        count+=1
    print(chr(count + ord('A')))






test = int(input())
for i in range(test):
    submit()