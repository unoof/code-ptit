import heapq

def submit():
    n = int(input())
    A = list(map(int, input().split()))

    A.sort(reverse=True)
    pq = []
    var1 = A[0]*A[1]; var2 = A[n-1]*A[n-2]*A[0]; var3 = A[n-1]*A[n-2]
    heapq.heappush(pq, var1)
    heapq.heappush(pq, var2)
    heapq.heappush(pq, var3)
    heapq.heappush(pq, var1*A[2])

    print(pq[3])




submit()