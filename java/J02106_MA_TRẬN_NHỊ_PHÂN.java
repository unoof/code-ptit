import java.util.Scanner;

public class submit {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        
        int count = 0;
        int total = 0;
        for (int i = 1; i <= n*3; i++) {
            int temp = scan.nextInt();
            if (temp == 1) {
                count++;
            }
            else {
                count--;
            }

            if (i%3 == 0) {
                if (count > 0) {
                    total++;
                }
                count = 0;
            }
        }
        System.out.println(total);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}