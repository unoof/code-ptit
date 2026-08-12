import java.util.Scanner;

public class J01003_GIẢI_PHƯƠNG_TRÌNH_BẬC_NHẤT {
    public static void func(Scanner scan) {
        double x = scan.nextInt();
        double y = scan.nextInt();

        if (x == 0 && y != 0) {
            System.out.println("VN");
        }
        else if (x == 0 && y == 0) {
            System.out.println("VSN");
        }
        else {
            System.out.printf("%.2f", (-y/x));
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}