import java.util.Scanner;

public class J01002_TÍNH_TỔNG_N_SỐ_NGUYÊN_DƯƠNG_ĐẦU_TIÊN {
    public static void func(Scanner scan) {
        long x = scan.nextInt();

        System.out.println(x*(x+1)/2);
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