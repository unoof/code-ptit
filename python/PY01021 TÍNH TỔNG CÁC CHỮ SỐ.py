def submit():
    s = input()

    char = sorted([i for i in s if i.isalpha()])
    num = sum(int(i) for i in s if i.isdigit())
    print("".join(map(str, char)), end="")
    print(num)













test = int(input())
for i in range(test):
    submit()