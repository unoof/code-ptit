import java.math.BigInteger;
import java.util.Scanner;

class temp {
    long x;
    long y;

    public temp(long x, long y) {
        this.x = x;
        this.y = y;
        this.fix();
    }

    private long gcd() {
        return BigInteger.valueOf(this.x).gcd(BigInteger.valueOf(this.y)).longValue();
    }

    private void fix() {
        long g = gcd();
        x = x/g;
        y = y/g;
    }

    public static temp plus(temp p1, temp p2) {
        temp tmp = new temp(0, 1);
        tmp.x = p1.x*p2.y + p2.x*p1.y;
        tmp.y = p1.y*p2.y;
        tmp.fix();

        return tmp;
    }

    public static temp multi(temp p1, temp p2) {
        temp tmp = new temp(0, 1);
        tmp.x = p1.x * p2.x;
        tmp.y = p1.y * p2.y;
        tmp.fix();

        return tmp;
    }

    @Override
    public String toString() {
        return String.format("%d/%d", x, y);
    }
}


public class J04014_TÍNH_TOÁN_PHÂN_SỐ {
    public static void func(Scanner scan) {
        temp A = new temp(scan.nextLong(), scan.nextLong());
        temp B = new temp(scan.nextLong(), scan.nextLong());

        temp C = temp.multi(temp.plus(A, B), temp.plus(A, B));
        temp D = temp.multi(A, temp.multi(B, C));

        System.out.println(C + " " + D);
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