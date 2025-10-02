def submit():
    d = int(input())
    s = input()
    alpha = [0]*127
    maxx = 0

    for i in range(len(s)):
        alpha[ord(s[i])] += 1
        maxx = max(maxx, alpha[ord(s[i])])
    maxi = (len(s)+1)/d

    print(1 if maxx <= maxi else -1)

test = int(input())
for i in range(test):
    submit()