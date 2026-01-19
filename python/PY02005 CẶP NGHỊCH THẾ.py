def submit():
    n = int(input())
    A = list(map(int, input().split()))
    count = 0

    def merge_sort(start, end):
        nonlocal count
        if (end-start) <= 1:
            return
        mid = (start+end)//2

        merge_sort(start, mid)
        merge_sort(mid, end)

        temp = []
        i, j = start, mid
        while i < mid and j < end:
            if A[i] > A[j]:
                temp.append(A[j])
                count += mid-i
                j+=1
            else:
                temp.append(A[i])
                i+=1

        temp.extend(A[i:mid])
        temp.extend(A[j:end])

        A[start:end] = temp

    merge_sort(0, n)
    print(count)






submit()