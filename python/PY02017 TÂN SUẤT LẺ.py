from collections import Counter

def submit():
    n = int(input())
    A = list(map(int, input().split()))

    temp = Counter(A)

    for key, val in temp.items():
        if val&1:
            print(key)
            return





test = int(input())
for i in range(test):
    submit()