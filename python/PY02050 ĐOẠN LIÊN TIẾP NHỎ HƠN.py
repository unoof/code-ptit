def submit():
    n = int(input())
    A = list(map(int, input().split()))
    ans = [0]*n
    stack = []

    for i in range(n):
        temp = 1
        while stack and stack[-1][0] <= A[i]:
            temp += stack[-1][2]
            stack.pop()
        stack.append([A[i], i, temp])
        ans[i] = temp


    print(*ans)










test = int(input())
for i in range(test):
    submit()