def submit():
    n = int(input())
    A = list(map(int, input().split()))
    B = []
    ans = []
    for i in range(n):
        B.append([A[i], i])
    B.sort()

    def cmp(A):
        s1 = ""
        for i in A:
            s1 += str(i) + " "
        return s1

    def recursion(A, placed, start, end, pre_placed, count):
        if start == end:
            return
        
        for j in range(2):
            if A[start] > A[pre_placed]:
                if j == 1:
                    placed[start] = j
                    count += 1
                    pre_placed = start
            elif j == 1:
                return
            
            if start == end-1:
                if count >= 2:
                    temp = []
                    for i in range( end):
                        if placed[i]:
                            temp.append(A[i])
                    ans.append(temp)
            else:
                recursion(A, placed, start+1, end, pre_placed, count)
            
            if j == 1:
                placed[start] = False


    for i in B:
        placed = [False]*n
        placed[i[1]] = True
        recursion(A, placed, i[1]+1, n, i[1], 1)
    
    ans.sort(key=cmp)

    for i in ans:
        print(" ".join(map(str, i)))




submit()