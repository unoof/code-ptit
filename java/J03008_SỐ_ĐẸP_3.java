import java.util.Scanner;

public class J03008_SỐ_ĐẸP_3 {
    public static void func(Scanner scan) {
        String s = scan.next();

        int i = 0;
        int j = s.length()-1;

        while (i <= j) {
            if (s.charAt(i) != s.charAt(j)
                || (s.charAt(i) != '2'
                && s.charAt(i) != '3'
                && s.charAt(i) != '5'
                && s.charAt(i) != '7')
                ) {
                System.out.println("NO");
                return;
            }
            i++; j--;
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