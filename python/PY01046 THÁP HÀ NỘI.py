def recursion(A, C, B, deep):
    if deep <= 1:
        print(A + " -> " + C);
    else:
        recursion(A, B, C, deep-1)
        print(A + " -> " + C)
        recursion(B, C, A, deep-1)

def submit():
    n = int(input())

    recursion("A", "C", "B", n)





submit()