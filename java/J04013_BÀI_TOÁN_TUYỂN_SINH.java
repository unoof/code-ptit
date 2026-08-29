import java.text.DecimalFormat;
import java.util.Scanner;

class Student {
    String id;
    String name;
    float p1;
    float p2;
    float p3;

    public Student(String id, String name, float p1, float p2, float p3) {
        this.id = id;
        this.name= name;
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    private float gift() {
        if (id.charAt(2) == '1') {
            return (float) 0.5;
        }
        else if (id.charAt(2) == '2') {
            return (float) 1;
        }
        else {
            return (float) 1.5;
        }
    }

    private boolean pass() {
        return p1*2 + p2 + p3 + gift() >= 24;
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.#");
        return String.format("%s %s %s %s %s", id, name, df.format(gift()), df.format(p1*2 + p2 + p3), pass() ? "TRUNG TUYEN" : "TRUOT");
    }
}

public class J04013_BÀI_TOÁN_TUYỂN_SINH {
    public static void func(Scanner scan) {
        Student stu = new Student(scan.nextLine(), scan.nextLine(), scan.nextFloat(), scan.nextFloat(), scan.nextFloat());

        System.out.println(stu);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}