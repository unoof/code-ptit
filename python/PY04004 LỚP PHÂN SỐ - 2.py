from math import gcd

class divine:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def process(self):
        print(f"{self.a//gcd(self.a, self.b)}/{self.b//gcd(self.a, self.b)}")

def total(p, q):
    numerator = p.a*q.b + q.a*p.b
    denominator = p.b*q.b
    return numerator, denominator

try:
    A = list(map(int, input().split()))
    p = divine(A[0], A[1])
    q = divine(A[2], A[3])
except (ValueError, IndexError):
    print("INVALID")

numerator, denominator = total(p, q)
temp = divine(numerator, denominator)
temp.process()
