import bisect

def submit():
    n = int(input())
    A = list(map(int, input().split()))

    def check(A, n):
        temp = []
        for i in A:
            pos = bisect.bisect_right(temp, i)
            if pos == len(temp):
                temp.append(i)
            else:
                temp[pos] = i
        return n-len(temp)

    print(check(A, n))


test = int(input())
for _ in range(test):
    submit()