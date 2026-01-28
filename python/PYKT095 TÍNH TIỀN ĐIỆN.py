class ICPC:
    def __init__(self, id, name, team, school):
        self.id = id
        self.name = name
        self.team = team
        self.school = school


def submit():
    n = int(input())
    B = dict()

    for i in range(n):
        team, school = input(), input()
        B[f"Team{i+1:02d}"] = [team, school]

    n = int(input())
    A = []

    for i in range(n):
        name, team = input(), input()
        A.append(ICPC(i+1, name, B[team][0], B[team][1]))

    A.sort(key=lambda x:(x.name))
    for i in A:
        print(f"C{i.id:03d} {i.name} {i.team} {i.school}")



submit()