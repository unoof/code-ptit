def submit():
    n = int(input())
    s = str(input())
    
    check = [False]*11
    for i in s:
        if i.isdigit() == True:
            check[ord(i)-ord('0')] = True
    
    for i in range(11):
        if check[i] == True:
            print(i, end=" ")
    print()



test = int(input())
for i in range(test):
    submit()
