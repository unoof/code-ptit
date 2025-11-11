import sys

def submit():
    A = list()
    for line in sys.stdin:
        temp = line.split()

        if temp[0] == "push":
            A.append(temp[1])
        elif temp[0] == "show":
            if len(A) != 0:
                print(*A)
            else:
                print("empty")
        else:
            A.pop()


submit()
