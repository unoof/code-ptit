def recursion(store, placed, j):
    for i in range(n):
        if placed[i] == False:
            store[j] = i
            placed[i] = True

            if j == n-1:
                for i in store:
                    print(chr(i+ord("A")), end="")
                print(end=" ")
            else:
                recursion(store, placed, j+1)
            placed[i] = False

def submit():
    global n
    A = str(input())
    n = len(A)
    store = [0]*n
    placed = [False]*n

    recursion(store, placed, 0)
    print()

test = int(input())
for i in range(test):
    submit()