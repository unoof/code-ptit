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

def check(A, n):
    for i in range(n):
        if A[i] != A[n-i-1]:
            return False
    return True



n = input()
n = int(n)
A = []
for i in range(n):
    A.append(0)

for i in range(max(n)+1):
    if check(A, n):
        for j in range(n):
            print(A[j], end=" ")
        print()
    A = update(A, n)