import java.util.Scanner;

public class J01009_TỔNG_GIAI_THỪA {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        
        long f = 0;
        long s = 1;

        for (int i = 1; i <= n; i++) {
            f += s*i;
            s *= i;
        }
        System.out.println(f);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}