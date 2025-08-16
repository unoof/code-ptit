def c(n, k):
    total = 1
    for i in range(1, k+1):
        total *= (n-i+1)
        total /= i
    return int(total)

def update(A, n, k):
    i = k-1
    while A[i] == n-k+i+1:
        i -= 1
    if i == -1:
        return

    A[i] += 1
    for j in range(i+1, k):
        A[j] = A[i]+j-i

    return A

def submit():
    n, k = map(int, input().split())
    A = []
    for i in range(1, k+1):
        A.append(i)

    for i in range(c(n,k)):
        for j in A:
            print(j, end = "")
        print(end = " ")
        A = update(A, n, k)

    print()

test_num = int(input())
for i in range(test_num):
    submit()