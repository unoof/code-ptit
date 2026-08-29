import java.util.Scanner;

class nhanVien {
    String id;
    String name;
    int salary;
    int time;
    String role;
    int payOut = 0;
    int support = 0;

    public nhanVien(String name, int salary, int time, String role) {
        this.id = "NV01";
        this.name = name;
        this.salary = salary;
        this.time = time;
        this.role = role;
        base();
        this.payOut = this.salary*this.time;
    }

    private void base() {
        switch (this.role) {
            case "GD":
                this.support += 250000;
                break;
            case "PGD":
                this.support += 200000;
                break;
            case "TP":
                this.support += 180000;
                break;
            default:
                this.support += 150000;
                break;
        }
    }

    private int gift() {
        if (this.time >= 25) {
            return this.payOut/5;
        }
        else if (this.time >= 22) {
            return this.payOut/10;
        }
        return 0;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d %d", this.id, this.name, this.payOut, gift(), this.support, this.payOut+gift()+this.support);
    }
}

public class J04012_BÀI_TOÁN_TÍNH_CÔNG {
    public static void func(Scanner scan) {
        nhanVien nv = new nhanVien(scan.nextLine(), scan.nextInt(), scan.nextInt(), scan.next());

        System.out.println(nv);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}