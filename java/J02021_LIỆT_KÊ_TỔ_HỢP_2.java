import java.util.Scanner;

public class J02021_LIỆT_KÊ_TỔ_HỢP_2 {
    public static long P(int n, int k) {
        long total = 1;
        for (int i = 1; i <= n-k; i++) {
            total *= n-i+1;
            total /= i;
        }
        return total;
    }

    public static void recur(int max, int last, int[] A, int index, int max_index) {
        if (index == max_index) {
            for (int i : A) {
                System.out.print(i);
            }
            System.out.print(" ");
            return;
        }

        for (int i = last; i <= max; i++) {
            A[index++] = i;
            recur(max, i+1, A, index, max_index);
            A[--index] = 0;
        }
    }

    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int k = scan.nextInt();

        int[] A = new int[k];
        recur(n, 1, A, 0, k);
        System.out.println();
        System.out.printf("Tong cong co %d to hop", P(n, k));
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}