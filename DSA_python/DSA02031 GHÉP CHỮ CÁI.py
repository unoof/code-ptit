def submit():
    c = input()
    n = ord(c)-ord('A')+1
    store = [0]*n
    placed = [False]*n

    def is_consonant(a) -> bool:
        return a == 'A' or a == 'E'
    
    def check(A):
        for i in range(1, len(A)-1):
            if A[i] == 'E' or A[i] == 'A':
                if not (is_consonant(A[i-1]) or is_consonant(A[i+1])):
                    return False
        return True
    
    def recursion(store, placed, j):
        if j == n:
            if check(store):
                print("".join(map(str, store)))
            return
        
        for i in range(n):
            if placed[i] == False:
                store[j] = chr(ord('A')+i)
                placed[i] = True

                recursion(store, placed, j+1)
                placed[i] = False


    recursion(store, placed, 0)



submit()