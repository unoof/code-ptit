import java.util.Scanner;
import java.lang.Math;

public class J01005_CHIA_TAM_GIÁC {
    public static double get_height(int n, int h, int i) {
        return (Math.sqrt(i)*h)/Math.sqrt(n);
    }

    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int h = scan.nextInt();

        for (int i = 1; i < n; i++) {
            System.out.printf("%.6f ", get_height(n, h, i));
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        while (t-- > 0) {
            func(scan);
        }

        scan.close();
    }
}