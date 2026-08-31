import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Item {
    String id;
    String name;
    int quantity;
    long each;
    long payOut;
    int free;

    public Item(String id, String name, int quantity, long each, int free) {
        this.id = id;
        this.name = name;
        this.quantity = quantity;
        this.each = each;
        this.payOut = (long) quantity*each;
        this.free = free;
    }

    public long getPayOut() {
        return payOut;
    }

    public static void order(List<Item> Items) {
        Collections.sort(Items, new Comparator<Item>() {
            @Override
            public int compare(Item o1, Item o2) {
                return Long.compare(o2.getPayOut(), o1.getPayOut());
            }
        });
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d %d", id, name, quantity, each, free, payOut-free);
    }
}

public class J05012_TÍNH_TIỀN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        List<Item> items = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            scan.nextLine();
            Item item = new Item(scan.nextLine(), scan.nextLine(), scan.nextInt(), scan.nextLong(), scan.nextInt());
            items.add(item);
        }
        Item.order(items);

        for (Item Item : items) {
            System.out.println(Item);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}