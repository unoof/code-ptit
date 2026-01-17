def submit():
    p, q = input().split()
    temp = input().split()
    if len(temp) == 1:
        x1 = temp[0]
        x2 = input()
    else:
        x1, x2 = temp

    if p > q: p, q = q, p

    min_sum = int(x1.replace(str(q), str(p))) + int(x2.replace(str(q), str(p)))
    max_sum = int(x1.replace(str(p), str(q))) + int(x2.replace(str(p), str(q)))

    print(min_sum, max_sum)


test = int(input())
for i in range(test):
    submit()