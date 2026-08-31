import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Customer {
    String id;
    String name;
    int room;
    int[] in;
    int[] out;
    int days = 1;
    int bonus;
    long cost;
    int costEach;

    public Customer(int id, String name, int room, String dateIn, String dateOut, int bonus) {
        this.id = String.format("KH%02d", id);
        this.name = name;
        this.room = room;
        this.bonus = bonus;
        this.in = fixDate(dateIn);
        this.out = fixDate(dateOut);
        this.days = findDays();
        findCost();
    }

    private int[] fixDate(String s) {
        String[] date = s.split("/");
        int[] real = new int[3];

        for (int i = 0; i < 3; i++) {
            real[i] = Integer.valueOf(date[i]);
        }
        return real;
    }
    
    private int findDays() {
        int total = 1;
        if (out[2] - in[2] > 0) {
            for (int i = in[2]+1; i < out[2]; i++) {
                if (i%4 == 0) {
                    total += 366;
                }
                else {
                    total += 365;
                }
            }
        }

        int[] monthsIn = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int[] monthsOut = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (in[2]%4 == 0) {
            monthsIn[1] = 29;
        }
        if (out[2]%4 == 0) {
            monthsOut[1] = 29;
        }

        if (in[2] != out[2]) {
            for (int i = in[1]+1; i < 13; i++) {
                total += monthsIn[i-1];
            }
            total += monthsIn[in[1]-1] - in[0];

            for (int i = 0; i < out[1]-1; i++) {
                total += monthsOut[i];
            }
            total += out[0];
        }
        else {
            int totalIn = in[0];
            int totalOut = out[0];

            for (int i = 0; i < in[1]-1; i++) {
                totalIn += monthsIn[i];
            }
            for (int i = 0; i < out[1]-1; i++) {
                totalOut += monthsOut[i];
            }
            total += totalOut - totalIn;
        }
        return total;
    }

    private void findCost() {
        if (room >= 400) {
            this.costEach = 80;
        }
        else if (room >= 300) {
            this.costEach = 50;
        }
        else if (room >= 200) {
            this.costEach = 34;
        }
        else {
            this.costEach = 25;
        }

        this.cost = days*costEach + bonus;
    }

    public long getCost() {
        return cost;
    }

    public static void order(List<Customer> customers) {
        Collections.sort(customers, new Comparator<Customer>() {
            @Override
            public int compare(Customer cus1, Customer cus2) {
                long cost1 = cus1.getCost();
                long cost2 = cus2.getCost();

                return Long.compare(cost2, cost1);
            }
        });
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d", id, name, room, days, cost);
    }
}

public class J05016_HÓA_ĐƠN_KHÁCH_SẠN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();

        List<Customer> customers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            scan.nextLine();
            Customer customer = new Customer(i+1, scan.nextLine(), scan.nextInt(), scan.next(), scan.next(), scan.nextInt());
            customers.add(customer);
        }
        Customer.order(customers);
        
        for (Customer customer : customers) {
            System.out.println(customer);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}