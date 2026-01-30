from collections import Counter

def submit():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))

    temp = Counter(A)

    ans = [[key, val] for key, val in temp.items()]
    check = set(val for _, val in temp.items())

    ans.sort(key=lambda x:(-x[1], x[0]))

    if len(check) == 1:
        print("NONE")
        return
    
    i = 1
    while True:
        if ans[i][1] == ans[i-1][1]:
            i +=1
        else:
            break
    print(ans[i][0])


submit()