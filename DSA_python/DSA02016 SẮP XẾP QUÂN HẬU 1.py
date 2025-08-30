def submit():
    n = int(input())
    times = 0
    cols = [False]*n
    diagonal_main = [False]*(2*n-1)
    diagonal_rev = [False]*(2*n-1)

    def solution(row):
        nonlocal times
        if row == n:
            times += 1
            return

        for col in range(n):
            if not (cols[col] or diagonal_main[col-row+n-1] or diagonal_rev[col+row]):
                cols[col] = diagonal_main[col-row+n-1] = diagonal_rev[col+row] = True

                solution(row+1)
                cols[col] = diagonal_main[col-row+n-1] = diagonal_rev[col+row] = False
    solution(0)
    return times


test = int(input())
for i in range(test):
    print(submit())