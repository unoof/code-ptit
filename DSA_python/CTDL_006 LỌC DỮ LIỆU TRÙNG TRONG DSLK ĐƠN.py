n = int(input())
A = list(map(int, input().split()))
temp = list(dict.fromkeys(A))

for i in temp:
    print(i, end = " ")