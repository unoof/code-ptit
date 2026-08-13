import java.util.Scanner;

public class J01016_CHỮ_SỐ_4_VÀ_CHỮ_SỐ_7 {
    public static void func(Scanner scan) {
        String s = scan.next();

        int count = 0;
        for (char i : s.toCharArray()) {
            if (i == '4' || i == '7') {
                count++;
            }
        }

        if (count == 4 || count == 7) {
            System.out.println("YES");
        }
        else {
            System.out.println("NO");
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}