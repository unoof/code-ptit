def submit():
    try:
        while True:
            n = int(input())
            if n == 0: return
            A = []
            for _ in range(n):
                temp = list(map(int, input().split()))
                A.extend(temp)
            print("BANG NHAU" if min(A) == max(A) else f"{min(A)} {max(A)}")
    except ValueError:
        pass



submit()