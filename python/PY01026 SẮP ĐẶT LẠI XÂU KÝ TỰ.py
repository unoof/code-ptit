def submit(n):
    s1 = input()
    s2 = input()

    if len(s1) != len(s2):
        print(f"Test {n}: NO")
        return

    temp = dict()
    for i, j in zip(s1, s2):
        temp[i] = temp.get(i, 0) + 1
        temp[j] = temp.get(j, 0) - 1

    for key, val in temp.items():
        if val != 0:
            print(f"Test {n}: NO")
            return
    print(f"Test {n}: YES")











test = int(input())
for i in range(test):
    submit(i+1)