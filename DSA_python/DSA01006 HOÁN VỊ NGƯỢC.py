def p(n):
    total = 1
    for i in range(n):
        total *= (i+1)
    return int(total)

def sort_list(A, start, end):
    B = []
    for i in range(start, end):
        B.append(A[i])
    B.sort(reverse = True)

    j = 0
    for i in range(start, end):
        A[i] = B[j]
        j += 1
    return A

def update(A, n):
    i = n-2
    while A[i] < A[i+1]:
        i -= 1
    if i < 0:
        return
    
    k = n-1
    while A[i] < A[k]:
        k -= 1
    A[i], A[k] = A[k], A[i]
    sort_list(A, i+1, n)
    return A

def submit():
    n = int(input())
    A = []
    for i in range(n):
        A.append(n-i)

    for i in range(p(n)):
        for j in A:
            print(j, end = "")
        print(end = " ")
        update(A, n)

    print()

test_num = int(input())
for i in range(test_num):
    submit()