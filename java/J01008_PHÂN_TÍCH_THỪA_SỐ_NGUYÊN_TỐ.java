import java.util.Scanner;

public class J01008_PHÂN_TÍCH_THỪA_SỐ_NGUYÊN_TỐ {
    public static void func(Scanner scan, int i) {
        int n = scan.nextInt();
        System.out.printf("Test %d: ", i);

        int temp = 2;
        while (n > 1) {
            int count = 0;
            while (n%temp == 0) {
                count++;
                n /= temp;
            }

            if (count != 0) System.out.printf("%d(%d) ", temp, count);
            temp++;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            func(scan, i);
        }

        scan.close();
    }
}