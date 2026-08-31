import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Player {
    String id;
    String name;
    int[] in;
    int[] out;

    public Player(String id, String name, String in, String out) {
        this.id = id;
        this.name = name;
        this.in = splitTime(in.trim());
        this.out = splitTime(out.trim());
    }

    private int[] splitTime(String n) {
        String[] temp = n.split(":");

        int[] time = new int[2];
        time[0] = Integer.valueOf(temp[0]);
        time[1] = Integer.valueOf(temp[1]);
        return time;
    }

    private int[] totalTime() {
        int[] ans = new int[2];
        
        if (out[0] < in[0]) {
            out[0] += 24;
        }
        if (out[1] < in[1]) {
            out[1] += 60;
            out[0] --;
        }

        ans[0] = out[0] - in[0];
        ans[1] = out[1] - in[1];
        return ans;
    }

    public static void order(List<Player> players) {
        Collections.sort(players, new Comparator<Player>() {
            @Override
            public int compare(Player p1, Player p2) {
                int[] time1 = p1.totalTime();
                int[] time2 = p2.totalTime();

                if (time1[0] == time2[0]) {
                    return Integer.compare(time2[1], time1[1]);
                }
                return Integer.compare(time2[0], time1[0]);
            }
        });
    }
    
    @Override
    public String toString() {
        int[] time = totalTime();
        return String.format("%s %s %d gio %d phut", id, name, time[0], time[1]);
    }
}

public class J05011_TÍNH_GIỜ {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        List<Player> players = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            scan.nextLine();
            Player player = new Player(scan.nextLine(), scan.nextLine(), scan.next(), scan.next());
            players.add(player);
        }
        Player.order(players);
        
        for (Player player : players) {
            System.out.println(player);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}