def submit():
    n = int(input())
    A = ["A", "B", "C"]
    save = [0, 0, 0]

    def check():
        for j in range(2):
            if save[j] > save[j+1]:
                return False
        return True

    def recursion(i, n, ans):
        if i == n:
            if check() and all(save):
                print(ans)
            return
        
        for j in range(3):
            save[j] += 1
            recursion(i+1, n, ans + A[j])
            save[j] -= 1

    for i in range(3, n+1):
        recursion(0, i, "")





submit()