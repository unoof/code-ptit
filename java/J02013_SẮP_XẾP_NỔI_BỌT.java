import java.util.Scanner;

public class J02013_SẮP_XẾP_NỔI_BỌT {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[] A = new int[n];

        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
        }

        int count = 1;
        for (int i = 0; i < A.length-1; i++) {
            int index = 0;
            boolean check = false;
            for (int j = index+1; j < A.length; j++) {
                if (A[index] > A[j]) {
                    A[index] += A[j];
                    A[j] = A[index] - A[j];
                    A[index] -= A[j];
                    check = true;
                    index = j;
                }
                else {
                    index = j;
                }
            }

            if (check) {
                System.out.printf("Buoc %d: ", count++);
                for (int k : A) {
                    if (k != 1000) {
                        System.out.print(k + " ");
                    }
                }
                System.out.println();
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}