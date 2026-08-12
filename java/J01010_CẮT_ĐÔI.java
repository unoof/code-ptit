import java.util.Scanner;

public class J01010_CẮT_ĐÔI {
    public static void func(Scanner scan) {
        String n = scan.next();
        char[] A = n.toCharArray();
        
        for (int i = 0; i < A.length; i++) {
            if (A[i] == '0' || A[i] == '8' || A[i] == '9') {
                A[i] = '0';
            }
            else if (A[i] == '1') {
                continue;
            }
            else {
                System.out.println("INVALID");
                return;
            }
        }

        for (int i = 0; i < A.length; i++) {
            if (A[i] == '0') {
                A[i] = 'z';
                continue;
            }
            else {
                break;
            }
        }

        if (A[A.length-1] == 'z') {
            System.out.println("INVALID");
        }
        else {
            for (int i = 0; i < A.length; i++) {
                if (A[i] != 'z') {
                    System.out.print(A[i]);
                }
            }
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            func(scan);
        }

        scan.close();
    }
}