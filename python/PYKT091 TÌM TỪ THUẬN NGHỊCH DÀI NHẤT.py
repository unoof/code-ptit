def check(s):
    for i in range(len(s)//2+1):
        if s[i] != s[len(s)-i-1]: return False
    return True

def submit():
    try:
        save = list(f.read().split())
        temp = dict()
        for i in range(len(save)):
            if not check(save[i]):
                continue
            if save[i] not in temp:
                temp[save[i]] = [1, i]
            else:
                temp[save[i]][0] += 1
        same = []
        for key, val in temp.items():
            same.append([key, val[0], val[1]])

        same.sort(key=lambda x: (-len(x[0]), x[2]))
        print(f"{same[0][0]} {same[0][1]}")
        for i in range(1, len(same)):
            if len(same[i][0]) == len(same[i-1][0]):
                print(f"{same[i][0]} {same[i][1]}")
            else:
                break

    except (ValueError, EOFError):
        pass

try:
    with open("VANBAN.in", 'r') as f:
        submit()
    f.close()
except FileNotFoundError:
    pass