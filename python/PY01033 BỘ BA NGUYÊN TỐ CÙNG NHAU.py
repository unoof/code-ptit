import math

def submit():
    start, end = map(int, input().split())
    A = list()

    def recursion(start, end, layers, current):
        layers += 1
        for i in current:
            if math.gcd(start, i) != 1:
                return
        current.append(start)

        if layers == 3:
            A.append(current[:])
        else:
            for i in range(start+1, end+1):
                recursion(i, end, layers, current)
        current.pop()
    
    for i in range(start, end+1):
        recursion(i, end, 0, [])
    
    for i in A:
        print(f"({i[0]}, {i[1]}, {i[2]})")








submit()