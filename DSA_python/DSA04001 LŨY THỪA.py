def submit():
    MOD = int(1e9+7)

    n, k = map(int, input().split())

    def power(n, k):
        if k == 0: return 1
        temp = power(n, k>>1)
        if k%2==0: return int((temp*temp)%MOD)
        return int((n*((temp*temp)%MOD))%MOD)
    
    print(power(n, k))


test = int(input())
for i in range(test):
    submit()