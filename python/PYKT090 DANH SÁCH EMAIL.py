def submit():
    try:
        save = list(f.read().split())
        for i in range(len(save)):
            save[i] = save[i].lower()
        save = sorted(list(set(save)))
        print("\n".join(save))

    except (ValueError, EOFError):
        pass

try:
    with open("CONTACT.in", 'r') as f:
        submit()
    f.close()
except FileNotFoundError:
    pass