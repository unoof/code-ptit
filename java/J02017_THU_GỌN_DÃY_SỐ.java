import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class J02017_THU_GỌN_DÃY_SỐ {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        int[] A = new int[n];
        Deque<Integer> s = new ArrayDeque<>();

        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
        }

        for (int i = 0; i < A.length; i++) {
            if (s.isEmpty()) {
                s.push(A[i]);
                continue;
            }

            if ((s.peek() + A[i])%2 == 0) {
                s.pop();
            }
            else {
                s.push(A[i]);
            }
        }

        System.out.println(s.size());
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}