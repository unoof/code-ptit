import java.util.Scanner;

public class J01025_HÌNH_VUÔNG {
    public static int find_best(int[] A) {
        int max = -1;
        int min = 10000000;
        for (int i : A) {
            if (i > max) {
                max = i;
            }
            if (i < min) {
                min = i;
            }
        }
        return max-min;
    }

    public static void func(Scanner scan) {
        int[] x = new int[4];
        int[] y = new int[4];

        int count = 0;
        for (int i = 0; i < 8; i++) {
            if ((i&1) == 1) {
                y[count++] = scan.nextInt();
            }
            else {
                x[count] = scan.nextInt();
            }
        }

        int find_x = find_best(x);
        int find_y = find_best(y);
        System.out.println(find_x*find_x > find_y*find_y ? find_x*find_x : find_y*find_y);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}