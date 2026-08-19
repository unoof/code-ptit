import java.util.Scanner;

public class J03004_CHUẨN_HÓA_XÂU_HỌ_TÊN_1 {
    public static void fix(char[] s) {
        for (int i = 0; i < s.length; i++) {
            if (i == 0) {
                System.out.print(Character.toUpperCase(s[i]));
            }
            else {
                System.out.print(Character.toLowerCase(s[i]));
            }
        }
        System.out.print(" ");
    }

    public static void func(Scanner scan) {
        String[] s = scan.nextLine().split(" ");

        for (int i = 0; i < s.length; i++) {
            if (!s[i].isEmpty()) {
                fix(s[i].toCharArray());
            }
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < t; i++) {
            func(scan);
        }

        scan.close();
    }
}