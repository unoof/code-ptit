import sys

def rotate(s, n):
    return chr((ord(s) + n - ord('A'))%26 + ord('A'))

def submit():
    s = sys.stdin.readline().strip()

    A = list(s[:len(s)//2])
    B = list(s[len(s)//2:])

    total_left, total_right = 0, 0

    for i, j in zip(A, B):
        total_left += ord(i) - ord('A')
        total_right += ord(j) - ord('A')

    for i in range(len(s)//2):
        A[i] = rotate(A[i], total_left)
        B[i] = rotate(B[i], total_right)

    for i in range(len(s)//2):
        A[i] = rotate(A[i], ord(B[i]) - ord('A'))

    print("".join(map(str, A)))





test = int(sys.stdin.readline())
for _ in range(test):
    submit()