def remove_words(s):
    if len(s) > 100:
        s = s[:101]
        while not s[-1].isspace():
            s = s[:len(s)-1]
    return s

def submit():
    n = int(input())

    for i in range(n):
        s = input().strip()
        s = remove_words(s)
        print(s)



submit()