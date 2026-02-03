import sys

def submit():
    n = int(sys.stdin.readline().strip())

    visited = [0]*4
    prime = "2357"

    def recursion(deep, A, count, max):
        if deep == max:
            if all(visited) and A[-1] != "2":
                print(A)
            return

        if max-deep < 4-count:
            return

        for i in range(4):
            if visited[i] == 0:
                count += 1
            visited[i] += 1

            recursion(deep+1, A + prime[i], count, max)

            visited[i] -= 1
            if visited[i] == 0:
                count -= 1
    
    for i in range(4, n+1):
        recursion(0, "", 0, i)









submit()