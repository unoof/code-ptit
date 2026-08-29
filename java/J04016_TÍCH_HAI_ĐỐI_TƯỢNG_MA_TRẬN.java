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

    @Override
    public String toString() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
        return "";
    }
}

public class J04016_TÍCH_HAI_ĐỐI_TƯỢNG_MA_TRẬN {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), p = sc.nextInt();
        Matrix a = new Matrix(n,m);
        a.nextMatrix(sc);
        Matrix b = new Matrix(m,p);
        b.nextMatrix(sc);
        System.out.println(a.mul(b));
    }
    public static void main8572433(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), p = sc.nextInt();
        Matrix a = new Matrix(n,m);
        a.nextMatrix(sc);
        Matrix b = new Matrix(m,p);
        b.nextMatrix(sc);
        System.out.println(a.mul(b));
    }
}
