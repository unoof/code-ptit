import java.util.Scanner;

public class J01013_TỔNG_ƯỚC_SỐ_1 {
    static int[] primes;
    static int prime_count;

    public static void prime_num() {
        boolean[] not_prime = new boolean[100001];
        primes = new int[100001];
        prime_count = 0;
        
        for (int i = 2; i <= 100000; i++) {
            if (!not_prime[i]) {
                primes[prime_count++] = i;
                for (long j = (long) i*i; j <= 100000; j += i) {
                    not_prime[(int) j] = true;
                }
            }
        }
    }

    public static void func(Scanner scan) {
        int n = scan.nextInt();
        prime_num();
        
        long total = 0;
        for (int i = 0; i < n; i++) {
            int k = scan.nextInt();

            for (int j = 0; j < prime_count; j++) {
                int prime = primes[j];
                if ((long) prime*prime > k) break;

                while (k%prime ==0) {
                    total += prime;
                    k /= prime;
                }
            }
            if (k > 1) {
                total += k;
            }
        }

        System.out.println(total);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}