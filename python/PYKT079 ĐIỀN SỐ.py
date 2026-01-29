def submit():
    n = int(input())
    A = list(map(int, input().split()))
    
    A = set(A)
    print((max(A)-min(A)+1) - len(A))



test = int(input())
for i in range(test):
    submit()