import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class J01022_XÂU_NHỊ_PHÂN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        long k = scan.nextLong();

        List<Long> fibo = new ArrayList<>();
        fibo.add(1L);
        fibo.add(1L);
        for (int i = 2; i < n; i++) {
            fibo.add(fibo.get(i-2) + fibo.get(i-1));
        }

        while (n > 2) {
            long left = fibo.get(n-3);
            if (k <= left) {
                n -= 2;
            }
            else {
                k -= left;
                n -= 1;
            }
        }

        System.out.println(n == 1 ? "0" : "1");
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