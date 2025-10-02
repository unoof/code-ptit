def submit():
    n, k = map(int, input().split())
    count = 1

    while True:
        if k&1:
            print(count)
            break
        k >>= 1
        count += 1

test = int(input())
for _ in range(test):
    submit()
