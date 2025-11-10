def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    count = 0

    for i in A:
        if i == k:
            count+=1

    print(count if count != 0 else -1)



test = int(input())
for i in range(test):
    submit()
