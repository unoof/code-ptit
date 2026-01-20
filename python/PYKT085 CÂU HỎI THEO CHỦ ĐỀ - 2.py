def submit():
    n = int(input())
    
    count = 0
    save = ""
    for i in range(n):
        s = input()
        if s == "":
            print(f"{save}: {count}")
            count = 0
            save = ""
        elif save == "":
            save = s
        else:
            count += 1
    print(f"{save}: {count}")











submit()
