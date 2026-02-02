def submit():
    n = int(input())

    still = [True]*n
    ans = []

    def recursion(deep, build):
        if deep == n:
            ans.append(build[:])
            return
        for i in range(n):
            if still[i]:
                build.append(i+1)
                still[i] = False
                recursion(deep+1, build)
                build.pop()
                still[i] = True

    recursion(0, [])

    print(len(ans))
    print(" ".join("".join(map(str, i)) for i in reversed(ans)))







test = int(input())
for _ in range(test):
    submit()