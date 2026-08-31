import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Student {
    String id;
    String name;
    String classes;
    String email;

    public Student(String id, String name, String classes, String email) {
        this.id = id;
        this.name = name;
        this.classes = classes;
        this.email = email;
    }

    public String getId() {
        return id;
    }

    public static void order(List<Student> students) {
        Collections.sort(students, new Comparator<Student>() {
            @Override
            public int compare(Student stu1, Student stu2) {
                String id1 = stu1.getId();
                String id2 = stu2.getId();

                return id1.compareTo(id2);
            }
        });
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", id, name, classes, email);
    }
}

public class J05021_SẮP_XẾP_THEO_MÃ_SINH_VIÊN {
    public static void func(Scanner scan) {

        List<Student> students = new ArrayList<>();
        while (scan.hasNext()) {
            Student student = new Student(scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine());
            students.add(student);
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