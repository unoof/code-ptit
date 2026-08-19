import java.util.Arrays;
import java.util.Scanner;

public class J02023_LỰA_CHỌN_THAM_LAM {
    public static void find_min(int n, int s) {
        int[] A = new int[n];
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                for (int j = 1; j <= 9; j++) {
                    int temp = (n-i-1)*9 + j + total;

                    if (temp >= s) {
                        A[i] = j;
                        total += j;
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
            else {
                for (int j = 0; j <= 9; j++) {
                    int temp = (n-i-1)*9 + j + total;

                    if (temp >= s) {
                        A[i] = j;
                        total += j;
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
        }

        for (int i : A) {
            System.out.print(i);
        }
    }

    public static void find_max(int n, int s) {
        int[] A = new int[n];
        Arrays.fill(A, 0);

        int index = 0;
        while (s >= 9) {
            A[index++] = 9;
            s -= 9;
        }
        if (s != 0) {
            A[index] = s;
        }

        for (int i : A) {
            System.out.print(i);
        }
    }

    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int s = scan.nextInt();

        if (9*n < s || 1 > s) {
            System.out.println(-1 + " " + -1);
            return;
        }
        find_min(n, s);
        System.out.print(" ");
        find_max(n, s);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}