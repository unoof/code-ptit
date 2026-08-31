import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Student {
    String id;
    int year;
    String name;
    String classes;
    String email;

    public Student(String id, String name, String classes, String email) {
        this.id = id;
        this.name = name;
        this.classes = classes;
        this.email = email;
        takeYear();
    }

    private void takeYear() {
        String temp = "20" + classes.charAt(1) + classes.charAt(2);
        this.year = Integer.valueOf(temp);
    }

    public int getYear() {
        return year;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", id, name, classes, email);
    }
}

public class J05023_LIỆT_KÊ_SINH_VIÊN_THEO_KHÓA {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        scan.nextLine();

        Map<Integer,List<Student>> studentMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            Student student = new Student(scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine());
            studentMap.computeIfAbsent(student.getYear(), k -> new ArrayList<>()).add(student);
        }

        int k = scan.nextInt();
        for (int i = 0; i < k; i++) {
            int year = scan.nextInt();
            System.out.printf("DANH SACH SINH VIEN KHOA %d:\n", year);
            for (Student student : studentMap.getOrDefault(year, new ArrayList<>())) {
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