def submit():
    s = input()
    alpha = [0]*26
    maxx = 0

    for i in range(len(s)):
        alpha[ord(s[i])-ord('a')] += 1
        maxx = max(maxx, alpha[ord(s[i])-ord('a')])
    maxi = (len(s)+1)/2

    print(1 if maxx <= maxi else -1)

test = int(input())
for i in range(test):
    submit()