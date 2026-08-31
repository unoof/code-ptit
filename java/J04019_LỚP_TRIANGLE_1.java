import java.util.Scanner;

class Point {
    double x;
    double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public static Point nextPoint(Scanner scan) {
        double x = scan.nextDouble();
        double y = scan.nextDouble();
        return new Point(x, y);
    }

    public double distance(Point p) {
        return Math.sqrt((this.x - p.x)*(this.x - p.x) + (this.y - p.y)*(this.y - p.y));
    }

    public double distance(Point p1, Point p2) {
        return Math.sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    }
}

class Triangle {
    double a;
    double b;
    double c;
    
    public Triangle(Point p1, Point p2, Point p3) {
        this.a = p1.distance(p2);
        this.b = p2.distance(p3);
        this.c = p3.distance(p1);
    }

    public String getPerimeter() {
        return String.format("%.3f", this.a + this.b + this.c);
    }

    public boolean valid() {
        return this.a + this.b > this.c && this.a + this.c > this.b && this.b + this.c > this.a;
    }
}

public class J04019_LỚP_TRIANGLE_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- >0){
            Triangle a = new Triangle(Point.nextPoint(sc), Point.nextPoint(sc), Point.nextPoint(sc));
            if(!a.valid()){
                System.out.println("INVALID");
            } else{
                System.out.println(a.getPerimeter());
            }
        }
    }
}
