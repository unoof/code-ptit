n = int(input())
A = list(map(int, input().split()))
k = int(input())

for i in A:
    if i == k:
        continue
    print(i, end = " ")