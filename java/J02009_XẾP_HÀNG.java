import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class J02009_XẾP_HÀNG {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        Map<Integer, List<Integer>> clock = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            int t1 = scan.nextInt();
            int t2 = scan.nextInt();
            clock.computeIfAbsent(t1, k -> new ArrayList<>()).add(t2);
        }

        long time = 0;
        for (Map.Entry<Integer, List<Integer>> entry : clock.entrySet()) {
            if (entry.getKey() > time) {
                time = entry.getKey();
            }
            for (int i = 0; i < entry.getValue().size(); i++) {
                time += entry.getValue().get(i);
            }
        }

        System.out.println(time);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}