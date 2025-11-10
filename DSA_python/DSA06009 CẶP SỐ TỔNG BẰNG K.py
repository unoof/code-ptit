def submit():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    def check():
        temp = dict()
        count = 0
        for i in range(n):
            need = k-A[i]
            if temp.get(need) != None:
                count += temp[need]
            if temp.get(A[i]) == None:
                temp[A[i]] = 1
            else:
                temp[A[i]]+=1
        return count
    
    print(check())




test = int(input())
for i in range(test):
    submit()
