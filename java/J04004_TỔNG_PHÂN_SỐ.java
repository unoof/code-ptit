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

    public temp plus(temp p) {
        temp tmp = new temp(0, 0);
        tmp.x = this.x*p.y + p.x*this.y;
        tmp.y = this.y*p.y;

        return tmp;
    }

    public void out() { 
        System.out.printf("%d/%d", tu(), mau());
    }
}

public class J04004_TỔNG_PHÂN_SỐ {
    public static void func(Scanner scan) {
        temp p1 = new temp(scan.nextLong(), scan.nextLong());
        temp p2 = new temp(scan.nextLong(), scan.nextLong());

        temp tmp = p1.plus(p2);
        
        tmp.out();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}