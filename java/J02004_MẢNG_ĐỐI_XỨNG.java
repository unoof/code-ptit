import java.util.Scanner;

public class J02004_MẢNG_ĐỐI_XỨNG {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[] A = new int[n];

        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
        }
        
        int i = 0;
        int j = n-1;

        while (i < j) {
            if (A[i] != A[j]) {
                System.out.println("NO");
                return;
            }
            i++; j--;
        }
        System.out.println("YES");
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        while (t-- > 0) {
            func(scan);
        }

        scan.close();
    }
}