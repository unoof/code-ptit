import java.util.Scanner;

public class J02101_IN_MA_TRẬN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[][] A = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = scan.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            if (i%2 != 0) {
                for (int j = n-1; j >= 0; j--) {
                    System.out.print(A[i][j] + " ");
                }
            }
            else {
                for (int j = 0; j < n; j++) {
                    System.out.print(A[i][j] + " ");
                }
            }
        }
        System.out.println();
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