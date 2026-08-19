import java.util.Scanner;

public class J02011_SẮP_XẾP_CHỌN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[] A = new int[n];

        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
        }

        for (int i = 0; i < A.length-1; i++) {
            int index = -1;
            int min = 1001;
            for (int j = i; j < A.length; j++) {
                if (min > A[j]) {
                    min = A[j];
                    index = j;
                }
            }

            if (i != index) {
                A[index] = A[i];
                A[i] = min;
            }

            System.out.printf("Buoc %d: ", i+1);
            for (int j : A) {
                System.out.print(j + " ");
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