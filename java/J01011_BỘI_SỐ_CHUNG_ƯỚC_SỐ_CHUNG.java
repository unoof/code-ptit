import java.math.BigInteger;
import java.util.Scanner;

public class J01011_BỘI_SỐ_CHUNG_ƯỚC_SỐ_CHUNG {
    public static void func(Scanner scan) {
        int a = scan.nextInt();
        int b = scan.nextInt();

        long temp = BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();

        long idk = ((long) a*b)/temp;
        System.out.printf("%d %d", idk, temp);
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            func(scan);
        }

        scan.close();
    }
}