def count_inversion(A):
    if len(A) <= 1: return 0
    mid = int(len(A)/2)

    L = A[:mid]
    R = A[mid:]
    inv = count_inversion(L) + count_inversion(R)

    i, j, k = 0, 0, 0
    while i < len(L) and  j < len(R):
        if L[i] <= R[j]:
            A[k] = L[i]
            k +=1; i+=1
        else:
            inv += len(L) - i
            A[k] = R[j]
            k+=1; j+=1
    
    while i < len(L): 
        A[k] = L[i]
        k+=1; i+=1
    while j < len(R): 
        A[k] = R[j]
        k+=1; j+=1

    return inv

def submit():
    n = int(input())
    A = list(map(int, input().split()))
    evens = list()
    for i in A:
        if i%2 == 0:
            evens.append(i)

    inv, sub = count_inversion(evens), 0

    i = 0
    while i < n:
        if A[i]&1:
            i+=1
        else:
            j = i
            block = list()
            while j < n and A[j]%2 == 0:
                block.append(A[j])
                j+=1
            
            if len(block) > 1:
                sub += count_inversion(block)
            
            i = j
    
    print(inv-sub)



submit()