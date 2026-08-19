import java.util.Scanner;

public class J02105_DANH_SÁCH_KỀ {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[][] A = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = scan.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.printf("List(%d) = ", i+1);
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    System.out.print((j+1) + " ");
                }
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}