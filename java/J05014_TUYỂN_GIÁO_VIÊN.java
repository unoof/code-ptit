import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Teacher {
    String id;
    String name;
    String subject;
    float point;
    String ans;

    public Teacher(int id, String name, String temp, float p1, float p2) {
        this.id = String.format("GV%02d", id);
        this.name = name;
        this.point = p1*2 + p2;
        getSubj(temp);
        check();
    }

    private void getSubj(String temp) {
        temp = temp.trim();
        char[] A = temp.toCharArray();

        if (A[0] == 'A') {
            this.subject = "TOAN";
        }
        else if (A[0] == 'B') {
            this.subject = "LY";
        }
        else if (A[0] == 'C') {
            this.subject = "HOA";
        }
        if (A[1] == '1') {
            this.point += 2;
        }
        else if (A[1] == '2') {
            this.point += 1.5;
        }
        else if (A[1] == '3') {
            this.point += 1;
        }
    }

    private void check() {
        if (point >= 18) {
            this.ans = "TRUNG TUYEN";
        }
        else {
            this.ans = "LOAI";
        }
    }

    public float getPoint() {
        return point;
    }

    public static void order(List<Teacher> teachers) {
        Collections.sort(teachers, new Comparator<Teacher>() {
            @Override
            public int compare(Teacher t1, Teacher t2) {
                float p1 = t1.getPoint();
                float p2 = t2.getPoint();

                return Float.compare(p2, p1);
            }
        });
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %.1f %s", id, name, subject, point, ans);
    }
}

public class J05014_TUYỂN_GIÁO_VIÊN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        List<Teacher> teachers = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            scan.nextLine();
            Teacher teacher = new Teacher(i+1, scan.nextLine(), scan.nextLine(), scan.nextFloat(), scan.nextFloat());
            teachers.add(teacher);
        }
        Teacher.order(teachers);

        for (Teacher teacher : teachers) {
            System.out.println(teacher);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}