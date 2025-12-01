def submit():
    s = input()

    A = list()
    count = 0

    for i in s:
        if (len(A) != 0 and 
            (i == ')' and A[-1] == '(') or
            (i == '}' and A[-1] == '{') or
            (i == ']' and A[-1] == '[')):
            A.pop()
        else:
            if i == ')':
                A.append('(')
                count+=1
            elif i == ']':
                A.append('[')
                count+=1
            elif i == '}':
                A.append('{')
                count+=1
            else:
                A.append(i)

    print(count + int(len(A)/2))



test = int(input())
for i in range(test):
    submit()