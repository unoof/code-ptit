from itertools import permutations

def submit():
    A = list(input())
    ans = permutations(A)
    for i in ans:
        print("".join(i))



submit()