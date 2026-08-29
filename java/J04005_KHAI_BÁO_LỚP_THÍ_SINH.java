import java.util.Scanner;

class Student {
    String name;
    String birth;
    float p1;
    float p2;
    float p3;

    private float total() {
        return this.p1 + this.p2 + this.p3;
    }

    public void out() {
        System.out.printf("%s %s %.1f", this.name, this.birth, total());
    }

    public Student(String name, String birth, float p1, float p2, float p3) {
        this.name = name;
        this.birth = birth;
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }
}

public class J04005_KHAI_BÁO_LỚP_THÍ_SINH {
    public static void func(Scanner scan) {
        Student s1 = new Student(scan.nextLine(), scan.nextLine(), scan.nextFloat(), scan.nextFloat(), scan.nextFloat());

        s1.out();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}