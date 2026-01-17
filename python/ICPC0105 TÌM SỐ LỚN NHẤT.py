def submit():
    s = input()
    A = []

    temp = ""
    for i in s:
        if i.isdigit():
            temp += i
        elif temp != "":
            A.append(int(temp))
            temp = ""
    
    if temp != "":
        A.append(int(temp))
    temp = ""

    print(max(A))



test = int(input())
for i in range(test):
    submit()