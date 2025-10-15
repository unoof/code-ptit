def submit():
    n, k, target = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    pointA, pointB = 0, 0
    while(pointA < n and pointB < k):
        if A[pointA] > B[pointB]:
            if target == 1:
                print(B[pointB])
                break
            pointB+=1
        elif A[pointA] < B[pointB]:
            if target == 1:
                print(A[pointA])
                break
            pointA+=1
        else:
            if target == 1:
                print(A[pointA])
                break
            pointA+=1
            pointB+=1
            target-=1
        target-=1


        
test = int(input())
for _ in range(test):
    submit()
