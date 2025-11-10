def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    
    def check():
        temp = dict()
        count = 0

        for i in range(n):
            need = k-A[i]
            if need in temp:
                count += temp[need]
            if A[i] in temp:
                temp[A[i]]+=1
            else:
                temp[A[i]] = 1
        return count
    
    print(check())
    

test = int(input())
for i in range(test):
    submit()
