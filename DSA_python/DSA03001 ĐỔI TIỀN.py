def submit():
    n = int(input())
    count = 0
    bank = [1, 2, 5, 10, 20, 50, 100, 200, 500, 1000]

    for i in range(9, -1, -1):
        if bank[i] <= n:
            count += n//bank[i]
            n %= bank[i]

    print(count)


test = int(input())
for i in range(test):
    submit()