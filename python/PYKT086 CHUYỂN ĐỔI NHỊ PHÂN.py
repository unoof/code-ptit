def covert(n, system):
    ans = ""
    while n != 0:
        temp = n%system
        if temp >= 10:
            i = "ABCDEF"
            temp = i[temp-10]
        ans = str(temp) + ans
        n //= system
    return ans

def submit():
    temp = int(f.readline().strip())
    n = f.readline().strip()

    decimal_integer = int(n, 2)
    
    print(covert(decimal_integer, temp))






with open("DATA.in", "r") as f:
    test = int(f.readline().strip())
    for i in range(test):
        submit()
f.close()