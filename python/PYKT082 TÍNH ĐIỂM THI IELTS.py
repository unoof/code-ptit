def round_num(n):
    decimal = n % 1
    if decimal < 0.25:
        return float(int(n))
    elif decimal < 0.75:
        return int(n) + 0.5
    else:
        return float(int(n) + 1)

def submit():
    A = list(input().split())

    save = []
    for i in range(41):
        if i < 3: save.append(1)
        elif i < 5: save.append(2.5)
        elif i < 7: save.append(3)
        elif i < 10: save.append(3.5)
        elif i < 13: save.append(4)
        elif i < 16: save.append(4.5)
        elif i < 20: save.append(5)
        elif i < 23: save.append(5.5)
        elif i < 27: save.append(6)
        elif i < 30: save.append(6.5)
        elif i < 33: save.append(7)
        elif i < 35: save.append(7.5)
        elif i < 37: save.append(8)
        elif i < 39: save.append(8.5)
        else: save.append(9)
    
    A[0], A[1] = save[int(A[0])], save[int(A[1])]
    A[2], A[3] = float(A[2]), float(A[3])
    total = sum(A)/4
    print(round_num(total))




test = int(input())
for i in range(test):
    submit()