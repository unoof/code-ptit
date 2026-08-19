import java.util.Scanner;

public class J03005_CHUẨN_HÓA_XÂU_HỌ_TÊN_2 {
    public static void fix(char[] s) {
        for (int i = 0; i < s.length; i++) {
            if (i == 0) {
                System.out.print(Character.toUpperCase(s[i]));
            }
            else {
                System.out.print(Character.toLowerCase(s[i]));
            }
        }
    }

    public static void func(Scanner scan) {
        String[] s = scan.nextLine().split("");

        String temp = "";
        boolean space = false;
        for (int i = 0; i < s.length; i++) {
            if (!s[i].equals(" ")) {
                temp += s[i];
                space = true;
                continue;
            }

            if (s[i].equals(" ") && space) {
                temp += " ";
                space = false;
                continue;
            }
        }
        
        String[] S = temp.split(" ");
        for (int i = 1; i < S.length; i++) {
            if (!S[i].isEmpty()) {
                fix(S[i].toCharArray());
                if (i != S.length-1) {
                    System.out.print(" ");
                }
            }
        }
        System.out.print(", ");
        System.out.println(S[0].toUpperCase());
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