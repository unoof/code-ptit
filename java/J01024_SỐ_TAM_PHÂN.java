import java.util.Scanner;

public class J01024_SỐ_TAM_PHÂN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        
        while (n > 0) {
            int temp = n%10;
            if (temp != 1 && temp != 2 && temp != 0) {
                System.out.println("NO");
                return;
            }
            n /= 10;
        }
        System.out.println("YES");
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