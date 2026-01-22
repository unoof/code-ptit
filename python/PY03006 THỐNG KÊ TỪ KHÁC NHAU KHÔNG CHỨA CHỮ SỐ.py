def check(s):
    ans = ""
    for i in s:
        if i.isalpha():
            ans += i
        elif i.isdigit():
            continue
        else:
            ans += " "
    return ans

def submit():
    n = int(input())
    A = dict()
    for i in range(n):
        line = list(input().split())
        for j in line:
            temp = list(check(j).split())
            for k in temp:
                A[k.lower()] = A.get(k.lower(), 0) + 1

    temp = [[key, val] for key, val in A.items()]
    temp.sort(key= lambda x: (-x[1], x[0]))
    for i in temp:
        print(" ".join(map(str, i)))





submit()