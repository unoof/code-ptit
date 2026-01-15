def submit():
    A = list(input())

    total = 0
    for i in A:
        total += int(i)
    
    print("YES" if total%3 == 0 else "NO")




test = int(input())
for i in range(test):
    submit()