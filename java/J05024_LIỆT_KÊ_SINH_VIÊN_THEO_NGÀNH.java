import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Student {
    String id;
    String degree;
    String name;
    String classes;
    String email;

    public Student(String id, String name, String classes, String email) {
        this.id = id;
        this.name = name;
        this.classes = classes;
        this.email = email;
        takeDegree();
    }

    private void takeDegree() {
        String temp = id.substring(3, 7);
        if (temp.equals("DCKT")) {
            this.degree = "KE TOAN";
        }
        else if (temp.equals("DCCN")) {
            this.degree = "CONG NGHE THONG TIN";
            if (this.classes.charAt(0) == 'E') {
                this.degree = "CONG NGHE THONG TIN E";
            }
        }
        else if (temp.equals("DCAT")) {
            this.degree = "AN TOAN THONG TIN";
            if (this.classes.charAt(0) == 'E') {
                this.degree = "AN TOAN THONG TIN E";
            }
        }
        else if (temp.equals("DCVT")) {
            this.degree = "VIEN THONG";
        }
        else if (temp.equals("DCDT")) {
            this.degree = "DIEN TU";
        }
    }

    public String getDegree() {
        return degree;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", id, name, classes, email);
    }
}

public class J05024_LIỆT_KÊ_SINH_VIÊN_THEO_NGÀNH {
    public static String fix(String s) {
        String temp = "";
        for (char iterable : s.toCharArray()) {
            temp += Character.toUpperCase(iterable);
        }
        return temp;
    }

    public static void func(Scanner scan) {
        int n = scan.nextInt();
        scan.nextLine();

        Map<String,List<Student>> studentMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            Student student = new Student(scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine());
            studentMap.computeIfAbsent(student.getDegree(), k -> new ArrayList<>()).add(student);
        }

        int k = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < k; i++) {
            String degree = scan.nextLine();
            degree = fix(degree);
            System.out.printf("DANH SACH SINH VIEN NGANH %s:\n", degree);
            for (Student student : studentMap.getOrDefault(degree, new ArrayList<>())) {
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