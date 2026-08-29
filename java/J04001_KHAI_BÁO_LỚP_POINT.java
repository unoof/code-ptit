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

public class J04001_KHAI_BÁO_LỚP_POINT {
    public static void func(Scanner scan) {
        Point p1 = new Point(scan.nextDouble(), scan.nextDouble());
        Point p2 = new Point(scan.nextDouble(), scan. nextDouble());

        System.out.printf("%.4f\n", p1.distance(p2));
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