import java.util.Scanner;

public class J03025_XÂU_ĐỐI_XỨNG {
    public static void func(Scanner scan) {
        String s = scan.next();

        int i = 0;
        int j = s.length()-1;
        boolean revive = true;
        
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                if (revive) {
                    revive = false;
                    continue;
                }
                System.out.println("NO");
                return;
            }
        }
        if (revive) {
            System.out.println(s.length()%2 == 1 ? "YES" : "NO");
        }
        else {
            System.out.println("YES");
        }
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