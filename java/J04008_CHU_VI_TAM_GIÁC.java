import java.util.Scanner;

class Point {
    double x;
    double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point(Point p) {
        this.x =p.x;
        this.y = p.y;
    }

    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
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
    
    public Triangle(double dis1, double dis2, double dis3) {
        this.a = dis1;
        this.b = dis2;
        this.c = dis3;
    }

    private boolean check() {
        return this.a + this.b > this.c && this.a + this.c > this.b && this.b + this.c > this.a;
    }

    @Override
    public String toString() {
        return check() ? String.format("%.3f", this.a + this.b + this.c) : "INVALID";
    }
}

public class J04008_CHU_VI_TAM_GIÁC {
    public static void func(Scanner scan) {
        Point p1 = new Point(scan.nextDouble(), scan.nextDouble());
        Point p2 = new Point(scan.nextDouble(), scan.nextDouble());
        Point p3 = new Point(scan.nextDouble(), scan.nextDouble());

        Triangle tri = new Triangle(p1.distance(p2), p2.distance(p3), p3.distance(p1));

        System.out.println(tri);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        for (int i = 0; i < t; i++) {
            func(scan);
        }

        scan.close();
    }
}