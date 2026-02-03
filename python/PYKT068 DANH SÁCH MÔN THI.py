class subject:
    def __init__(self, id, name, exam):
        self.id = id
        self.name = name
        self.exam = exam
    
    def __str__(self):
        return f"{self.id} {self.name} {self.exam}"

def submit():
    n = int(input())
    A = []
    
    for i in range(n):
        id = input()
        name = input()
        exam = input()
        A.append(subject(id, name, exam))

    A.sort(key=lambda x:(x.id))

    print("\n".join(map(str, A)))







submit()