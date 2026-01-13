def submit():
    a, k, n = map(int, input().split())

    first = ((a//k)+1)*k
    current = first
    temp = []

    while current <= n:
        temp.append(current-a)
        current += k
    
    if temp:
        print(*temp)
    else:
        print(-1)




submit()