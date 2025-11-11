import sys, heapq
data = sys.stdin.read().strip().split()
it = iter(data)

def submit():
    n = int(next(it))
    odd, even = list(), list()

    for i in range(n):
        temp = int(next(it))
        if i%2 == 0:
            odd.append(temp)
        else:
            even.append(temp)
    heapq.heapify(odd); heapq._heapify_max(even)
    
    for i in range(n):
        print(heapq.heappop(odd) if i%2 == 0 else heapq._heappop_max(even), end=" ")



submit()
