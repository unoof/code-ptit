def submit():
    s = input()

    track = ""
    for i in reversed(s):
        if i == "8":
            track += i
        elif i == "6":
            if len(track) > 2:
                print("NO")
                return
            track = ""
        else:
            print("NO")
            return

    print("YES" if len(track) < 3 else "NO")











submit()