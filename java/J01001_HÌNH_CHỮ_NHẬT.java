import java.util.Scanner;

public class J01001_HÌNH_CHỮ_NHẬT {
    public static void func() {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int y = scan.nextInt();

        if (x <= 0 || y <= 0) {
            System.out.println("0");
        }
        else {
            int p = (x+y)*2;
            int s = x*y;
            System.out.printf("%d %d", p, s);
        }
        scan.close();
    }

    public static void main(String[] args) {
        func();
    }
}