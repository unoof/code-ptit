import java.util.Scanner;

class Matrix {
    int n;
    int m;
    int[][] A;

    public Matrix(int n, int m) {
        this.n = n;
        this.m = m;
        this.A = new int[n][m];
    }

    public void nextMatrix(Scanner scan) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this.A[i][j] = scan.nextInt();
            }
        }
    }

    public Matrix mul(Matrix b) {
        Matrix ans = new Matrix(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    ans.A[i][j] += A[i][k] * b.A[k][j];
                }
            }
        }
        return ans;
    }

    public Matrix trans() {
        Matrix ans = new Matrix(m, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.A[j][i] = A[i][j];
            }
        }
        return ans;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sb.append(A[i][j] + " ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}

public class J04017_TÍCH_MA_TRẬN_VÀ_CHUYỂN_VỊ_CỦA_NÓ {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt(), m = sc.nextInt();
            Matrix a = new Matrix(n,m);
            a.nextMatrix(sc);
            Matrix b = a.trans();
            System.out.println(a.mul(b));
        }
    }
    public static void main6342611(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt(), m = sc.nextInt();
            Matrix a = new Matrix(n,m);
            a.nextMatrix(sc);
            Matrix b = a.trans();
            System.out.println(a.mul(b));
        }
    }
}

