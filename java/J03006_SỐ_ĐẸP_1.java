import java.util.Scanner;

public class J03006_SỐ_ĐẸP_1 {
    public static void func(Scanner scan) {
        String s = scan.next();

        int i = 0;
        int j = s.length()-1;

        while (i <= j) {
            if (s.charAt(i) != s.charAt(j--) || ((int) s.charAt(i++))%2 != 0) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        for (int i = 0; i < t; i++) {
            func(scan);
        }

        scan.close();
    }
}