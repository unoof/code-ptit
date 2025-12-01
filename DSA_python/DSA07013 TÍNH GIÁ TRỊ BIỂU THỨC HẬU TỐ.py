def submit():
    s = input()

    temp = "+/*-"
    A = list()
    
    for i in range(len(s)):
        if temp.find(s[i]) == -1:
            A.append(ord(s[i])-ord('0'))
        else:
            b = A.pop(); a = A.pop()
            if s[i] == '+':
                A.append(a+b)
            elif s[i] == '/':
                A.append(a//b)
            elif s[i] == '*':
                A.append(a*b)
            elif s[i] == '-':
                A.append(a-b)
        
    print(A[-1])



test = int(input())
for i in range(test):
    submit()