def submit():
    n, m, x = map(int, input().split())

    save = [[] for _ in range(n+1)]
    for i in range(m):
        temp = list(map(int, input().split()))
        save[temp[0]].append(temp[1])
        save[temp[1]].append(temp[0])

    visited = [False]*(n+1)
    visited[x] = True
    stack = [x]

    while stack:
        u = stack.pop()
        for i in save[u]:
            if not visited[i]:
                stack.append(i)
                visited[i] = True

    check = False
    for i in range(1, n+1):
        if not visited[i]:
            print(i)
            check = True
    if not check:
        print(0)









submit()