import heapq

def submit():
    n = int(input())
    A = list(map(int, input().split()))
    heapq.heapify(A)

    total, temp = 0, 0
    while len(A) != 1:
        temp += A[0]
        heapq.heappop(A)
        temp += A[0]
        heapq.heappop(A)

        total += temp
        heapq.heappush(A, temp)
        temp = 0
    
    print(total)

test = int(input())
for i in range(test):
    submit()