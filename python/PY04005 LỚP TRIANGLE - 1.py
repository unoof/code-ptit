import sys
from math import sqrt

class Triangle:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def perimeter(self, B, C):
        return distance(self, B) + distance(self, C) + distance(B, C)

def distance(A, B):
    return sqrt((A.x-B.x)**2 + (A.y-B.y)**2)

def check(ab, ac, bc):
    return ab+ac > bc and ab+bc > ac and ac+bc > ab

def submit(input):
    global i
    try:
        x1, y1, x2, y2, x3, y3 = map(float, input[i:i+6])
        i+=6
        a = Triangle(x1, y1)
        b = Triangle(x2, y2)
        c = Triangle(x3, y3)
    except (ValueError, IndexError):
        print("INVALID")
        return
    if check(distance(a, b), distance(a, c), distance(b, c)):
        print(f"{a.perimeter(b, c):.3f}")
    else:
        print("INVALID")

i = 1
input = sys.stdin.read().split()
for _ in range(int(input[0])):
    submit(input)