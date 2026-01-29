def submit():
    n = int(input())

    count = 0
    check = False
    ans = []
    i = 0
    while i < n:
        temp = input().split()
        if len(temp) == 7:
            if check:
                count += 1
                ans.append(1)
                check = False
            i += 3
            for _ in range(3):
                trash = input().split()
            count += 1
            ans.append(2)
        else:
            check = True
        i += 1
    
    if check:
        count += 1
        ans.append(1)

    print(count)
    print("\n".join(map(str, ans)))


submit()