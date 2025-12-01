def submit():
    n = int(input())
    A = list(map(int, input().split()))

    B = [A[-1]]; ans = [-1]

    for i in range(n-2, -1, -1):
        if len(B) != 0:
            if A[i] < B[-1]:
                ans.append(B[-1])
            else:
                for j in range(len(B)-1, -2, -1):
                    if j == -1:
                        ans.append(-1)
                    elif B[j] > A[i]:
                        ans.append(B[j])
                        break
            B.append(A[i])
    
    print(" ".join(map(str, reversed(ans))))



test = int(input())
for i in range(test):
    submit()