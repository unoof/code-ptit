import java.text.DecimalFormat;
import java.util.Scanner;

class Teacher {
    String id;
    String name;
    int salary;

    public Teacher(String id, String name, int salary) {
        this.id = id;
        this.name= name;
        this.salary = salary;
    }

    private int more() {
        if (id.startsWith("HT")) {
            return 2000000;
        }
        else if (id.startsWith("HP")) {
            return 900000;
        }
        return 500000;
    }

    private int howMuch() {
        String temp = id.substring(2, 4);
        return Integer.valueOf(temp);
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d", id, name, howMuch(), more(), salary*howMuch() + more());
    }
}

public class J04015_TÍNH_THU_NHẬP_GIÁO_VIÊN {
    public static void func(Scanner scan) {
        Teacher teac = new Teacher(scan.nextLine(), scan.nextLine(), scan.nextInt());

        System.out.println(teac);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}