import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student {
    int id;
    String name;
    String birth;
    float p1;
    float p2;
    float p3;

    public float total() {
        return this.p1 + this.p2 + this.p3;
    }
    
    public Student(int id, String name, String birth, float p1, float p2, float p3) {
        this.id = id;
        this.name = name;
        this.birth = birth;
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }
    
    @Override
    public String toString() {
        return String.format("%d %s %s %.1f", id, name, birth, total());
    }
}

public class J05009_TÌM_THỦ_KHOA_CỦA_KỲ_THI {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        List<Student> students = new ArrayList<>();

        float max = 0;
        for (int i = 0; i < n; i++) {
            scan.nextLine();
            Student stu = new Student(i+1, scan.nextLine(), scan.next(), scan.nextFloat(), scan.nextFloat(), scan.nextFloat());
            students.add(stu);

            if (max < stu.total()) {
                max = stu.total();
            }
        }

        for (Student student : students) {
            if (student.total() == max) {
                System.out.println(student);
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}