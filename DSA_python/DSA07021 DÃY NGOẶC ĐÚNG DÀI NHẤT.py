def submit():
    s = input()

    maxi = 0
    A = list()
    A.append(-1)

    for i in range(len(s)):
        c = s[i]
        if c == '(' or c == '[' or c == '{':
            A.append(i)
        else:
            if (len(A) != 0 and A[-1] != -1 and
                (c == ')' and s[A[-1]] == '(') or
                (c == ']' and s[A[-1]] == '[') or
                (c == '}' and s[A[-1]] == '{')):
                A.pop()
                maxi = max(maxi, i-A[-1])
            else:
                A.append(i)


    print(maxi)




test = int(input())
for i in range(test):
    submit()