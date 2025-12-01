def submit():
    s = input()

    temp = "+/*-"
    A = list()
    
    for i in range(len(s)-1, -1, -1):
        if temp.find(s[i]) == -1:
            A.append(s[i])
        else:
            a = A.pop(); b = A.pop()
            A.append(f"{a}{b}{s[i]}")
        
    print(A[-1])



test = int(input())
for i in range(test):
    submit()