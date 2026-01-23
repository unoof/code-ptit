import sys

def submit():
    n = int(sys.stdin.readline())
    A = []
    for i in range(n-1):
        A.append(int(sys.stdin.readline()))
    
    ans = 1
    for i in sorted(A):
        if i != ans:
            print(ans)
            return
        else:
            ans+=1






submit()