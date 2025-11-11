from collections import deque

def submit():
    n = int(input())
    A = deque(["1"])

    while A:
        res = A.popleft()
        if int(res)%n == 0:
            print(res)
            break
        A.append(res+"0"); A.append(res+"1")
    





for i in range(int(input())):
    submit()
