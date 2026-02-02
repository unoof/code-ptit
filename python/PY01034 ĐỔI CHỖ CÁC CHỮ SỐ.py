def search_min(temp, n):
    tmp = -1
    for i in range(len(temp)):
        if tmp == -1 and temp[i] < n:
            tmp = i
        elif temp[i] >= temp[tmp] and temp[i] < n:
            tmp = i
    return tmp

def submit():
    A = list(map(int, input()))

    temp = [A[-1]]
    for i in range(len(A)-2, -1, -1):
        if A[i] > A[i+1]:
            index = (len(temp) - search_min(temp, A[i])) + i
            A[index], A[i] = A[i], A[index]

            if A[0] == 0:
                print(-1)
                return
            temp.append(A[i])
            break
        else:
            temp.append(A[i])

    print("".join(map(str, A)) if A != temp[::-1] else -1)










test = int(input())
for i in range(test):
    submit()