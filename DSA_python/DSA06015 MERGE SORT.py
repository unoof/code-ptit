def sorting(A, start, mid, end):
    n1 = mid-start+1
    n2 = end-mid
    left = A[start:mid+1]
    right = A[mid+1:end+1]

    i, j, k = 0, 0, start
    while i < n1 and j < n2:
        if left[i] <= right[j]:
            A[k] = left[i]
            i+=1
        else:
            A[k] = right[j]
            j+=1
        k+=1
    while i < n1:
        A[k] = left[i]
        i+=1; k+=1
    while j < n2:
        A[k] = right[j]
        j+=1;k+=1

def merge_sort(A, start, end):
    if start < end:
        mid = (start+end)//2
        merge_sort(A, start, mid)
        merge_sort(A, mid+1, end)
        sorting(A, start, mid, end)

def submit():
    n = int(input())
    A = list(map(int, input().split()))

    merge_sort(A, 0, n-1)

    print(" ".join(map(str, A)))




test = int(input())
for i in range(test):
    submit()
