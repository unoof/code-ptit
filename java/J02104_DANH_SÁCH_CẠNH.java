import java.util.Scanner;

public class J02104_DANH_SÁCH_CẠNH {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[][] A = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = scan.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    System.out.printf("(%d,%d)\n", i+1, j+1);
                    A[i][j] = A[j][i] = 0;
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}