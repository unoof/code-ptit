import java.util.Arrays;
import java.util.Scanner;

public class J02012_SẮP_XẾP_CHÈN {
    public static void move(int[] A, int index, int num) {
        for (int i = 0; i < A.length; i++) {
            if (i == index) {
                for (int j = A.length-1; j > i; j--) {
                    A[j] = A[j-1];
                }
                A[i] = num;
                break;
            }
        }
    }

    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[] A = new int[n];

        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
        }

        int[] ans = new int[n];
        Arrays.fill(ans, 1000);
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < ans.length; j++) {
                if (A[i] < ans[j]) {
                    move(ans, j, A[i]);
                    break;
                }
            }

            System.out.printf("Buoc %d: ", i);
            for (int k : ans) {
                if (k != 1000) {
                    System.out.print(k + " ");
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