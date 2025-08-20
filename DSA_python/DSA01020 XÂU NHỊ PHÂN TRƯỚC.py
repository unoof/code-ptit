import sys

data = sys.stdin.read().strip().split()
it = iter(data)



def update(A):
    for i in range(len(A)-1, -1, -1):
        if A[i] == '1':
            A[i] = '0'
            break
        A[i] = '1'

def submit():
    A = list(next(it))

    update(A)
    for j in A:
        print(j, end = "")
    print()


test_num = int(next(it))
for i in range(test_num):
    submit()