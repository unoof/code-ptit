def submit():
    n = input()
    print("yes" if n.lower()[-3:] == ".py" else "no")



submit()