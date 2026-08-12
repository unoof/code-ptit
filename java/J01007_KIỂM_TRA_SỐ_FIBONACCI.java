import java.util.Scanner;

public class J01007_KIỂM_TRA_SỐ_FIBONACCI {
    public static void func(Scanner scan) {
        long n = scan.nextLong();

        long f1 = 1;
        long f2 = 1;

        while (true) {
            f1 = f2 + f1;
            f2 = f1 - f2;
            
            if (f1 > n) {
                break;
            }
        }

        if (f2 == n || n == 0) System.out.println("YES");
        else System.out.println("NO");
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