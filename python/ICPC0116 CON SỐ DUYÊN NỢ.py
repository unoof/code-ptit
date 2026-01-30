def submit():
    s = input()

    print("YES" if s[0] == s[-1] else "NO")



test = int(input())
for i in range(test):
    submit()