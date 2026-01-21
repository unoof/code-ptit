class Rectangle:
    def __init__(self, long, wide, c):
        self.long = long
        self.wide = wide
        self.c = c
    
    def perimeter(self):
        return (self.long + self.wide)*2
    def area(self):
        return self.long*self.wide
    def color(self):
        return self.c.capitalize()


try:
    arr = input().split()
    if int(arr[0]) > 0 and int(arr[1]) > 0:
        r = Rectangle(int(arr[0]), int(arr[1]), arr[2])
        print('{} {} {}'.format(r.perimeter(), r.area(), r.color()))
    else:
        print("INVALID")
except (ValueError, IndexError):
    print("INVALID")