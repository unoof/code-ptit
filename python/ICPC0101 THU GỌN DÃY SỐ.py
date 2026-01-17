def submit():
    n = int(input())
    A = list(map(int, input().split()))
    B = [A[0]]

    for i in A[1:]:
        if B:
            if (B[-1] + i)%2 == 0:
                B.pop()
                continue
        B.append(i)

    print(len(B))



submit()