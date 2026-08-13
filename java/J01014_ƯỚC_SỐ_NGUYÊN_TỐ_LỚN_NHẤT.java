import java.util.Scanner;

public class J01014_ƯỚC_SỐ_NGUYÊN_TỐ_LỚN_NHẤT {
    public static void func(Scanner scan) {
        long n = scan.nextLong();

        long last = 1;
        while (n%2 == 0) {
            n /= 2;
            last = 2;
        }
        for (long i = 3; i*i < n; i+=2) {
            while (n%i == 0) {
                n /= i;
                last = i;
            }
        }
        if (n > 1) {
            last = n;
        }
        
        System.out.println(last);
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