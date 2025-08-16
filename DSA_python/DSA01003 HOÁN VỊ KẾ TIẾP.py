def sort_list(A, start, end):
    B = []
    for i in range(start, end):
        B.append(A[i])

    B.sort()
    j = 0
    for i in range(start, end):
        A[i] = B[j]
        j += 1
    return A

def update(A, n):
    i = n-2
    while A[i] > A[i+1]:
        i -= 1

    if i != -1:
        k = n-1
        while A[k] < A[i]:
            k -= 1

        A[i], A[k] = A[k], A[i]
        A = sort_list(A, i+1, n)
    else:
        A.reverse()
    return A

def submit():
    n = int(input())
    A = list(map(int, input().split()))

    A = update(A, n)

    for i in A:
        print(i, end = " ")
    print()

test_num = int(input())
for i in range(test_num):
    submit()