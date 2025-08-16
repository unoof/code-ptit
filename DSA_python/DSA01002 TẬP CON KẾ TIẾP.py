def update(A, n, k):
    i = k-1
    while A[i] == n-k+i+1:
        i -= 1
    A[i] += 1
    if i == -1:
        for j in range(i+1, k):
            A[j] = j-i
    else:
        for j in range(i+1, k):
            A[j] = A[i]+j-i

    return A

def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    A = update(A, n, k)

    for i in A:
        print(i, end = " ")
    print()

test_num = int(input())
for i in range(test_num):
    submit()