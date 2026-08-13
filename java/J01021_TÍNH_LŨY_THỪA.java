import java.util.Scanner;

public class J01021_TÍNH_LŨY_THỪA {
    public static void func(long a, long b) {
        long temp = 1;
        while (b > 0) {
            if ((b&1) == 1) {
                temp = (temp*a)%(1000000000+7);
            }
            a = (a*a)%(1000000000+7);
            b >>= 1;
        }
        System.out.println(temp);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        while (true) {
            long a = scan.nextLong();
            long b = scan.nextLong();
            if (a == 0 && b == 0) {
                break;
            }
            func(a, b);
        }

        scan.close();
    }
}