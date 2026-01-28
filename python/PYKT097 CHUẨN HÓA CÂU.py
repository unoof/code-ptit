class process:
    def __init__(self, s):
        self.A = s.split()
    
    def change_words_format(self):
        self.A[0] = self.A[0].title()

    def check_new_line(self):
        if len(self.A[-1]) == 1:
            self.A[-2] = self.A[-2] + self.A[-1]
            self.A.pop()
        if self.A[-1][-1] not in (".", "?", "!"):
            self.A[-1] += "."

    def __str__(self):
        return " ".join(self.A)

def submit():
    A = []
    try:
        while True:
            s = input().lower().strip()
            temp = process(s)
            temp.change_words_format()
            temp.check_new_line()
            A.append(temp)

    except:
        pass    
    print("\n".join(map(str, A)))



submit()