def submit():
    A = list(input())

    total = 0
    for i in A:
        total += int(i)
    
    print("YES" if str(total) == str(total)[::-1] and total >= 10 else "NO")




test = int(input())
for i in range(test):
    submit()