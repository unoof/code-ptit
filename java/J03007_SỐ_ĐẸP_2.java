import java.util.Scanner;

public class J03007_SỐ_ĐẸP_2 {
    public static void func(Scanner scan) {
        String s = scan.next();

        int i = 1;
        int j = s.length()-2;
        long total = 16;

        if (s.charAt(0) != s.charAt(s.length()-1) || s.charAt(0) != '8') {
            System.out.println("NO");
            return;
        }
        while (i <= j) {
            if (s.charAt(i) != s.charAt(j--)) {
                System.out.println("NO");
                return;
            }
            total += ((long) (s.charAt(i++) - '0'))*2;
        }
        
        System.out.println(total%10 == 0 ? "YES" : "NO");
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