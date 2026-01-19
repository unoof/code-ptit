def covert(n, system):
    ans = ""
    while n != 0:
        temp = n%system
        if temp >= 10:
            i = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            temp = i[temp-10]
        ans = str(temp) + ans
        n //= system
    return ans

def submit():
    n, temp = map(int, input().split())
    
    print(covert(n, temp))






test = int(input())
for i in range(test):
    submit()