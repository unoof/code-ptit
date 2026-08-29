import java.math.BigInteger;
import java.util.Scanner;

class temp {
    long x;
    long y;

    public temp(long x, long y) {
        this.x = x;
        this.y = y;
    }

    private long gcd() {
        return BigInteger.valueOf(this.x).gcd(BigInteger.valueOf(this.y)).longValue();
    }

    private long tu() {
        return this.x/gcd();
    }

    private long mau() {
        return this.y/gcd();
    }

    public void out() {
        System.out.printf("%d/%d", tu(), mau());
    }
}


public class J04003_PHÂN_SỐ {
    public static void func(Scanner scan) {
        temp tmp = new temp(scan.nextLong(), scan.nextLong());

        tmp.out();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}