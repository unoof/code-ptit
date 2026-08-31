import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Player {
    String id;
    String name;
    String address;
    float speed;

    public Player(String name, String address, String time) {
        this.name = name.trim().replaceAll("\\s+", " ");
        this.address = address.trim().replaceAll("\\s+", " ");
        findId();
        findSpeed(findTotalTime(time.trim()));
    }

    private float findTotalTime(String temp) {
        String[] time = temp.split(":");

        float total = Float.valueOf(time[1])/60 + (Float.valueOf(time[0]) - 6);
        return total;
    }

    private void findSpeed(float time) {
        this.speed = 120/time;
    }

    private char takeFirst(String s) {
        return s.charAt(0);
    }

    private void findId() {
        String[] address = this.address.split(" ");
        String[] name = this.name.split(" ");

        String id = "";
        for (String string : address) {
            id += takeFirst(string);
        }
        for (String string : name) {
            id += takeFirst(string);
        }
        this.id = id;
    }

    public float getSpeed() {
        return speed;
    }

    public static void order(List<Player> players) {
        Collections.sort(players, new Comparator<Player>() {
            @Override
            public int compare(Player p1, Player p2) {
                float sp1 = p1.getSpeed();
                float sp2 = p2.getSpeed();

                return Float.compare(sp2, sp1);
            }
        });
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %.0f Km/h", id, name, address, speed);
    }
}

public class J05015_ĐUA_XE_ĐẠP {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        scan.nextLine();

        List<Player> players = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Player player = new Player(scan.nextLine(), scan.nextLine(), scan.nextLine());
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