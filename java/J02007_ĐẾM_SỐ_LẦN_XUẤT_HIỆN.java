import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class J02007_ĐẾM_SỐ_LẦN_XUẤT_HIỆN {
    public static void func(Scanner scan, int count) {
        int n = scan.nextInt();
        int[] A = new int[n];

        for (int i = 0; i < A.length; i++) {
            A[i] = scan.nextInt();
        }
        
        Map<Integer, Integer> ans = new LinkedHashMap<>();
        for (int i : A) {
            ans.put(i, ans.getOrDefault(i, 0)+1); 
        }

        System.out.printf("Test %d:\n", count);
        for (Map.Entry<Integer, Integer> entry : ans.entrySet()) {
            System.out.printf("%d xuat hien %d lan \n", entry.getKey(), entry.getValue());
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        for (int i = 0; i < t; i++) {
            func(scan, i+1);
        }

        scan.close();
    }
}