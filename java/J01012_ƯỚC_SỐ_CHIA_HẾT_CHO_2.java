import java.util.Scanner;

public class J01012_ƯỚC_SỐ_CHIA_HẾT_CHO_2 {
    public static void func(Scanner scan) {
        int n = scan.nextInt();

        int temp = n/2;
        if (temp*2 != n) {
            System.out.println(0);
        }
        else {
            int count = 0;
            for (int i = 1; (long) i*i <= temp; i++) {
                if (temp%i == 0) {
                    if (i*i == temp) {
                        count++;
                    }
                    else {
                        count+=2;
                    }
                }
            }
            System.out.println(count);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            func(scan);
        }

        scan.close();
    }
}