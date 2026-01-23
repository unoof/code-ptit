def submit():
    s = input()

    count = 0
    stack = []
    for i in s:
        if i == "(":
            count+=1
            stack.append(count)
            print(count, end=" ")
        elif i == ")":
            print(stack.pop(), end=" ")
    print()


test = int(input())
for i in range(test):
    submit()