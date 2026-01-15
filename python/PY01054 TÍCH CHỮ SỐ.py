def submit():
    A = list(input())

    total = 1
    for i in A:
        if i != '0':
            total *= int(i)
    
    print(total)




test = int(input())
for i in range(test):
    submit()