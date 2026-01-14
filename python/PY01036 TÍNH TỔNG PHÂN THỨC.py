def submit():
    n = int(input())

    total = 0
    if n%2 == 1:
        for i in range(1, n+1, 2):
            total += 1/i
    else:
        for i in range(2, n+1, 2):
            total += 1/i

    total = round(total, 6)
    print(f"{total:.6f}")





test = int(input())
for i in range(test):
    submit()