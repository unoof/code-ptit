import sys

class imaginary_num:
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary
    
    def plus(self, other):
        return imaginary_num(self.real + other.real, self.imaginary + other.imaginary)
    
    def multiply(self, other):
        real = self.real * other.real - self.imaginary * other.imaginary
        imaginary = self.real*other.imaginary + self.imaginary*other.real
        return imaginary_num(real, imaginary)


def submit(input):
    global i
    try:
        x1, y1, x2, y2 = map(int, input[i:i+4])
        i+=4
        a = imaginary_num(x1, y1)
        b = imaginary_num(x2, y2)
    except (ValueError, IndexError):
        print("INVALID")
        return
    
    temp = a.plus(b)
    C = temp.multiply(a)
    D = temp.multiply(temp)
    ans = ""
    if C.imaginary > 0:
        ans += str(C.real) + " + " + str(C.imaginary) + "i"
    else:
        ans += str(C.real) + " - " + str(C.imaginary) + "i"
    ans += ", "
    if D.imaginary > 0:
        ans += str(D.real) + " + " + str(D.imaginary) + "i"
    else:
        ans += str(D.real) + " - " + str(D.imaginary) + "i"
    print(ans)



i = 1
input = sys.stdin.read().split()
for _ in range(int(input[0])):
    submit(input)