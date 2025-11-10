def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    def cmp(a):
        return abs(k-a)
    
    A.sort(key=cmp)

    print(" ".join(map(str, A)))

test = int(input())
for i in range(test):
    submit()
