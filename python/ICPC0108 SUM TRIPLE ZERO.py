def submit():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()

    count = 0
    for i in range(n):
        if A[i] <= 0:
            first, last = i+1, n-1
            while first < last:
                total = A[first] + A[last] + A[i]
                if total == 0:
                    count += 1
                    first += 1
                elif total > 0:
                    last-=1
                else:
                    first +=1
    print(count)


test = int(input())
for i in range(test):
    submit()