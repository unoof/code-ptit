def submit():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()

    maxi = 0

    a, b, c = A[:3]
    x, y, z = A[-3:]
    maxi = max(y*z, x*y*z, a*b, a*b*z)
    

    print(maxi)









submit()