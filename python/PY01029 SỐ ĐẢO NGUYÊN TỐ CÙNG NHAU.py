import math

def rev(s):
    d = ""
    for i in range(len(s)-1, -1, -1):
        d+=s[i]
    return d

def submit():
    s = input()

    a, b = int(s), int(rev(s))
    print("YES" if math.gcd(a, b) == 1 else "NO")

test = int(input())
for _ in range(test):
    submit()