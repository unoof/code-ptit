import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class IntSet {
    int[] A;

    public IntSet(int[] A) {
        this.A = A;
        Arrays.sort(this.A);
    }

    public IntSet union(IntSet B) {
        List<Integer> C = new ArrayList<>();

        int x = 0;
        int y = 0;
        int last = 0;
        while (x < A.length && y < B.A.length) {
            if (A[x] > B.A[y]) {
                if (last != B.A[y]) {
                    C.add(B.A[y]);
                    last = B.A[y];
                }
                y++;
            }
            else if (A[x] < B.A[y]) {
                if (last != A[x]) {
                    C.add(A[x]);
                    last = A[x];
                }
                x++;
            }
            else {
                if (last != A[x]) {
                    C.add(A[x]);
                    last = A[x];
                }
                x++; y++;
            }
        }

        while (x < A.length) {
            if (last != A[x]) {
                C.add(A[x]);
                last = A[x];
            }
            x++;
        }
        while (y < B.A.length) {
            if (last != B.A[y]) {
                C.add(B.A[y]);
                last = B.A[y];
            }
            y++;
        }

        int[] ans = new int[C.size()];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = C.get(i);
        }
        return new IntSet(ans);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i : A) {
            sb.append(i + " ");
        }
        return sb.toString();
    }
}

public class J04021_LỚP_INTSET {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), a[] = new int[n], b[] = new int[m];
        for(int i = 0; i<n; i++) a[i] = sc.nextInt();
        for(int i = 0; i<m; i++) b[i] = sc.nextInt();
        IntSet s1 = new IntSet(a);
        IntSet s2 = new IntSet(b);
        IntSet s3 = s1.union(s2);
        System.out.println(s3);
    }
}
