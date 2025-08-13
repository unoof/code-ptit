def update(A, n):
    for i in range(n-1, -1, -1):
        if A[i] == 0:
            A[i] = 1
            break
        A[i] = 0
    return A

def max(n):
    total = 0
    for i in range(n):
        total = total*2 + 1
    return total

def check(temp, A, n, k) -> bool:
    total = 0
    for i in range(n):
        if temp[i] == 1:
            total += A[i]
    return total == k



n, k = map(int, input().split())
count = 0
temp = []
A = list(map(int, input().split()))

for i in range(n):
    temp.append(0);

for i in range(max(n)+1):
    if check(temp, A, n, k):
        for j in range(n):
            if temp[j] == 1:
                print(A[j], end=" ")
        print()
        count += 1
    temp = update(temp, n)
print(count)