def submit():
    temp = f.read().split()
    ans = []

    for i in temp:
        try:
            t = int(i)
            if len(i) > 18:
                ans.append(i)
        except (ValueError):
            ans.append(i)

    print(*sorted(ans))



with open("DATA.in", 'r') as f:
    submit()