def submit():
    x, y, z = map(int, input().split())
    i, j, k = 0, 0, 0

    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    out = []
    check = False

    while i < x and j < y and k < z:
        if A[i] == B[j] == C[k]:
            out.append(A[i])
            check = True
            i += 1; j += 1; k += 1
        elif A[i] > B[j]:
            j += 1
        elif B[j] > C[k]:
            k += 1
        else:
            i += 1

    print(" ".join(map(str, out)) if check == True else "NO")


test = int(input())
for i in range(test):
    submit()