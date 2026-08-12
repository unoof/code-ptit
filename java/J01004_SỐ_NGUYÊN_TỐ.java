import java.util.Scanner;

public class J01004_SỐ_NGUYÊN_TỐ {
    public static void func(Scanner scan) {
        int x = scan.nextInt();

        if (x < 2) {
            System.out.println("NO");
            return;
        }
        int i = 2;
        while (i*i <= x) {
            if (x%i == 0) {
                System.out.println("NO");
                break;
            }
            i++;
        }
        if (i*i > x) {
            System.out.println("YES");
        }
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