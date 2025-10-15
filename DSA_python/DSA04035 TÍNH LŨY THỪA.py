def submit():
    n, k = 0, 0
    
    def multiply(n, k):
        n = (n*k)%MOD
        return n

    def power(n, k):
        ans = 1
        while k:
            if k&1:
                ans = multiply(ans, n)
            n = multiply(n, n)
            k >>= 1
        return ans

    while True:
        n, k = map(int, input().split())
        if n == 0 and k == 0:
            break
        print(power(n, k)%MOD)


MOD = 10**9+7


submit()
