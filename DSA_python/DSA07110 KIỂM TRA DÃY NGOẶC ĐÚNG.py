def submit():
    s = input()
    if s[0] == ')' or s[0] == ']' or s[0] == '}':
        print("NO")
        return
    
    A = list()
    for i in s:
        if i == ')' and len(A) != 0:
            if A[-1] != '(':
                print("NO")
                return
            A.pop()
        elif i == ']' and len(A) != 0:
            if A[-1] != '[':
                print("NO")
                return
            A.pop()
        elif i == '}' and len(A) != 0:
            if A[-1] != '{':
                print("NO")
                return
            A.pop()
        else:
            A.append(i)
    
    print("YES")





test = int(input())
for i in range(test):
    submit()