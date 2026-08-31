import java.util.Scanner;

class Pair<A extends Number,B extends Number> {
    A first;
    B second;

    public Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }

    public boolean isPrime() {
        long num1 = first.longValue();
        long num2 = second.longValue();

        if (num1 < 2) return false;
        for (long i = 2; i * i <= num1; i++) {
            if (num1 % i == 0) return false;
        }

        if (num2 < 2) return false;
        for (long i = 2; i * i <= num2; i++) {
            if (num2 % i == 0) return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return first + " " + second;
    }
}

public class J04020_LỚP_PAIR {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            boolean check = false;
            for(int i = 2; i <= 2*Math.sqrt(n); i++){
                Pair<Integer, Integer> p = new Pair<>(i, n-i);
                if(p.isPrime()){
                    System.out.println(p);
                    check = true;
                    break; 
                }
            }
            if(!check) System.out.println(-1);
        }
    }
}
