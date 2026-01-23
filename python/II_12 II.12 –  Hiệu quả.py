import sys

def submit():
    start = list(map(int, sys.stdin.readline().split()))
    end = list(map(int, sys.stdin.readline().split()))

    if start[0] != end[0]:
        end[1] += 60*(end[0]-start[0] if end[0] > start[0] else end[0]+24-start[0])

    temp = (end[1] - start[1])*60 + end[2]-start[2]
    print(temp)





submit()