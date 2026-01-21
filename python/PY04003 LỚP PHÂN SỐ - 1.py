from math import gcd

class divine:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def process(self):
        print(f"{self.a//gcd(self.a, self.b)}/{self.b//gcd(self.a, self.b)}")


try:
    A = list(map(int, input().split()))
    temp = divine(A[0], A[1])
    temp.process()

except (ValueError, IndexError):
    print("INVALID")