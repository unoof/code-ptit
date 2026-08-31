import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
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

    public String getClasses() {
        return classes;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", id, name, classes, email);
    }
}

public class J05022_LIỆT_KÊ_SINH_VIÊN_THEO_LỚP {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        scan.nextLine();

        Map<String,List<Student>> studentMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            Student student = new Student(scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine());
            studentMap.computeIfAbsent(student.getClasses(), k -> new ArrayList<>()).add(student);
        }

        int k = scan.nextInt();
        for (int i = 0; i < k; i++) {
            String classes = scan.next();
            System.out.printf("DANH SACH SINH VIEN LOP %s:\n", classes);
            for (Student student : studentMap.get(classes)) {
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