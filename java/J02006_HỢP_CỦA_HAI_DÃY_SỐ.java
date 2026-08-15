import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class J02006_HỢP_CỦA_HAI_DÃY_SỐ {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int m = scan.nextInt();

        int[] A = new int[n];
        int[] B = new int[m];
        for (int i = 0; i < n+m; i++) {
            if (i >= n) {
                B[i-n] = scan.nextInt();
            }
            else {
                A[i] = scan.nextInt();
            }
        }

        Arrays.sort(A);
        Arrays.sort(B);
        List<Integer> ans = new ArrayList<>();

        int x = 0;
        int y = 0;
        int last = 0;
        while (x < n && y < m) {
            if (A[x] < B[y]) {
                if (last != A[x]) {
                    last = A[x];
                    ans.add(A[x]);
                }
                x++;
            }
            else if (A[x] > B[y]) {
                if (last != B[y]) {
                    last = B[y];
                    ans.add(B[y]);
                }
                y++;
            }
            else if (A[x] == B[y]) {
                if (last != A[x]) {
                    last = A[x];
                    ans.add(A[x]);
                }
                x++; y++;
            }
        }

        while (x < n) {
            if (last != A[x]) {
                last = A[x];
                ans.add(A[x]);
            }
            x++;
        }
        while (y < m) {
            if (last != B[y]) {
                last = B[y];
                ans.add(B[y]);
            }
            y++;
        }

        for (Integer i : ans) {
            System.out.printf("%d ", i);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}