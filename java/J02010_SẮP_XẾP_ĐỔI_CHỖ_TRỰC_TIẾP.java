import java.util.Scanner;

public class J02010_SẮP_XẾP_ĐỔI_CHỖ_TRỰC_TIẾP {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[] A = new int[n];

        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
        }

        for (int i = 0; i < A.length-1; i++) {
            for (int j = i+1; j < A.length; j++) {
                if (A[i] > A[j]) {
                    A[i] += A[j];
                    A[j] = A[i] - A[j];
                    A[i] -= A[j];
                }
            }
            System.out.printf("Buoc %d: ", i+1);
            for (int j = 0; j < A.length; j++) {
                System.out.printf("%d ", A[j]);
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