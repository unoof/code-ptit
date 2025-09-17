def submit():
    a, b = map(str, input().split())

    def maxi(a, b):
        a = a.replace('5', '6')
        b = b.replace('5', '6')
        return int(a) + int(b)
    
    def mini(a, b):
        a = a.replace('6', '5')
        b = b.replace('6', '5')
        return int(a) + int(b)

    print(mini(a, b), maxi(a, b))


submit()