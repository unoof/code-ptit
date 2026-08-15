import java.util.Scanner;

public class J01018_SỐ_KHÔNG_LIỀN_KỀ {
    public static void func(Scanner scan) {
        long n = scan.nextLong();

        int last = (int) (n%10);
        int count = last;
        n /= 10;
        while (n > 0) {
            int i = (int) (n%10);
            
            if (Math.abs(i-last) != 2) {
                System.out.println("NO");
                return;
            }
            last = i;
            count += i;
            n /= 10;
        }

        if (count%10 != 0) {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
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