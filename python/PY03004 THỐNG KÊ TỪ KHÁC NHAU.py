def check(s):
    ans = ""
    for i in s:
        if i.isalnum():
            ans += i
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
            for l in temp:
                A[l.lower()] = A.get(l.lower(), 0) + 1

    temp = [[key, val] for key, val in A.items()]
    temp.sort(key= lambda x: (-x[1], x[0]))
    for i in temp:
        print(" ".join(map(str, i)))





submit()