import java.util.Arrays;
import java.util.Scanner;

public class J02102_MA_TRẬN_XOẮN_ỐC_TĂNG_DẦN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[] A = new int[n*n];
        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
        }
        Arrays.sort(A);

        int[][] B = new int[n][n];
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int count = 0;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                B[top][i] = A[count++];
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                B[i][right] = A[count++];
            }
            right--;

            for (int i = right; i >= left; i--) {
                B[bottom][i] = A[count++];
            }
            bottom--;

            for (int i = bottom; i >= top; i--) {
                B[i][left] = A[count++];
            }
            left++;
        }
        
        for (int[] is : B) {
            for (int is2 : is) {
                System.out.print(is2 + " ");
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