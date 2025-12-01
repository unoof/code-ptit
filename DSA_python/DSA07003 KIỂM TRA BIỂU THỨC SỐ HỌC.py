def check(s):
    temp = "(+-*/"
    A = list()

    for i in s:
        if temp.find(i) != -1:
            A.append(i)
        elif i == ')':
            if A[len(A)-1] == '(':
                return True
            else:
                while A[len(A)-1] != '(':
                    A.pop()
                A.pop()
    
    return False

def submit():
    s = input()

    print("Yes" if check(s) == True else "No")


test = int(input())
for i in range(test):
    submit()