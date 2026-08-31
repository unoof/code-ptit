import java.util.Scanner;

class Point3D {
    int x;
    int y;
    int z;

    public Point3D(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public static boolean check(Point3D a, Point3D b, Point3D c, Point3D d) {
        return (b.x-a.x)*(c.y-a.y)*(d.z-a.z) +
               (b.y-a.y)*(c.z-a.z)*(d.x-a.x) +
               (b.z-a.z)*(c.x-a.x)*(d.y-a.y) -
               (b.z-a.z)*(c.y-a.y)*(d.x-a.x) -
               (b.y-a.y)*(c.x-a.x)*(d.z-a.z) -
               (b.x-a.x)*(c.z-a.z)*(d.y-a.y) == 0;
    }
}

public class J04011_BỐN_ĐIỂM_TRÊN_MẶT_PHẲNG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            Point3D p1 = new Point3D(sc.nextInt(),sc.nextInt(),sc.nextInt());
            Point3D p2 = new Point3D(sc.nextInt(),sc.nextInt(),sc.nextInt());
            Point3D p3 = new Point3D(sc.nextInt(),sc.nextInt(),sc.nextInt());
            Point3D p4 = new Point3D(sc.nextInt(),sc.nextInt(),sc.nextInt());
            
            if(Point3D.check(p1,p2,p3,p4)){
                System.out.println("YES");
            } else{
                System.out.println("NO");
            }
        }
    }
}
