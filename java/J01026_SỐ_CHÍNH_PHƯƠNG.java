import java.util.Scanner;

public class J01026_SỐ_CHÍNH_PHƯƠNG {
    public static void func(Scanner scan) {
        double n = scan.nextInt();
        
        int temp = (int) Math.sqrt(n);

        System.out.println(temp*temp == n ? "YES" : "NO");
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