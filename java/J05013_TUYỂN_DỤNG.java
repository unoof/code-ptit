import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Student {
    String id;
    String name;
    float p;
    String classes;

    public Student(int id, String name, float p1, float p2) {
        this.id = String.format("TS%02d", id);
        this.name = name;
        this.p = (fixPoint(p1) + fixPoint(p2))/2;
        separate();
    }

    private float fixPoint(float point) {
        if (point <= 10) {
            return point;
        }
        return point/10;
    }

    public float getP() {
        return p;
    }

    private void separate() {
        if (p > 9.5) {
            this.classes = "XUAT SAC";
        }
        else if (p >= 8) {
            this.classes = "DAT";
        }
        else if (p >= 5) {
            this.classes = "CAN NHAC";
        }
        else {
            this.classes = "TRUOT";
        }
    }

    public static void order(List<Student> students) {
        Collections.sort(students, new Comparator<Student>() {
            @Override
            public int compare(Student stu1, Student stu2) {
                float p1 = stu1.getP();
                float p2 = stu2.getP();

                return Float.compare(p2, p1);
            }
        });
    }

    @Override
    public String toString() {
        return String.format("%s %s %.2f %s", id, name, p, classes);
    }
}

public class J05013_TUYỂN_DỤNG {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        List<Student> students = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            scan.nextLine();
            Student stu = new Student(i+1, scan.nextLine(), scan.nextFloat(), scan.nextFloat());
            students.add(stu);
        }
        Student.order(students);

        for (Student student : students) {
            System.out.println(student);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}