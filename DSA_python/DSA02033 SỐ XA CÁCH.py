def submit():
    n = int(input())
    store = [0]*n
    placed = [False]*(n+1)
    
    def recursion(store, placed, j):
        if j == n:
            print("".join(map(str, store)))
            return
        
        for i in range(1, n+1):
            if placed[i] == False:

                if j > 0 and abs(store[j-1]-i) == 1: continue
                store[j] = i
                placed[i] = True

                recursion(store, placed, j+1)
                placed[i] = False


    recursion(store, placed, 0)
    print()


test = int(input())
for i in range(test):
    submit()