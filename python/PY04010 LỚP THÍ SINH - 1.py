import sys

class student:
    def __init__(self, name, birth, res1, res2, res3):
        self.name = name
        self.birth = birth
        self.res1 = res1
        self.res2 = res2
        self.res3 = res3

def submit():
    try:
        input = []
        for i in range(5):
            input.append(sys.stdin.readline().strip())
        name, birth, res1, res2, res3 = input[0], input[1], float(input[2]), float(input[3]), float(input[4])
        this = student(name, birth, res1, res2, res3)

    except (ValueError, IndexError):
        print("INVALID")
        return
    

    print(this.name, this.birth, (this.res1 + this.res2 + this.res3))





submit()