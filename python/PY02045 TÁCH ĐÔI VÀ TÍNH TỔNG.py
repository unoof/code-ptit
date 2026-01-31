def total(n):
    a = int(n[:len(n)//2])
    b = int(n[len(n)//2:])

    return str(a+b)

def submit():
    n = input()

    while len(n) != 1:
        n = total(n)
        print(n)












submit()