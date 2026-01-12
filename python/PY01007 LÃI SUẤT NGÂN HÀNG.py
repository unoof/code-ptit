def submit():
    n, x, m = map(float, input().split())

    count = 0
    while n < m:
        count+=1
        n = n + n*x/100
    print(count)



test = int(input())
for _ in range(test):
    submit()