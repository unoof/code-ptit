def submit():
    A = list(input())

    first, last = 0, len(A)-1
    while first < len(A)-1 and A[first] < A[first+1]:
        first+=1
    while last > 0 and A[last] < A[last-1]:
        last-=1

    print("YES" if first == last and 0 < first < len(A)-1 else "NO")





test = int(input())
for i in range(test):
    submit()