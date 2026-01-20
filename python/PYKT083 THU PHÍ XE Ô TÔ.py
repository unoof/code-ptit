def submit():
    n = int(input())
    
    A = {
        'Xe_con_5': 10000,
        'Xe_con_7': 15000,
        'Xe_tai_2': 20000,
        'Xe_khach_29': 50000,
        'Xe_khach_45': 70000,
    }

    save = dict()
    for i in range(n):
        temp = list(input().split())
        if temp[4] not in save:
            save[temp[4]] = 0
        if temp[3] == "OUT":
            continue
        else:
            save[temp[4]] += A[temp[1] + "_" + temp[2]]
    
    for key, val in save.items():
        print(f"{key}: {val}")











submit()
