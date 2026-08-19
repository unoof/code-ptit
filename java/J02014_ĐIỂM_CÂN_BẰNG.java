import java.util.Scanner;

public class J02014_ĐIỂM_CÂN_BẰNG {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[] A = new int[n];

        int l = 0;
        int r = 0;
        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
            r += A[i];
        }

        int index = n-1;
        l += A[index];
        r -= A[index--];
        r -= A[index];
        while (l != r && index > 1) {
            l += A[index];
            r -= A[--index];
        }

        System.out.println(index != 1 ? index+1 : -1);
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