import java.util.Scanner;

public class J01006_TÍNH_SỐ_FIBONACCI {
    public static void func(Scanner scan) {
        int n = scan.nextInt();

        long f1 = 1;
        long f2 = 1;

        for (int i = 2; i < n; i++) {
            f1 = f2 + f1;
            f2 = f1 - f2;
        }
        System.out.println(f1);
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