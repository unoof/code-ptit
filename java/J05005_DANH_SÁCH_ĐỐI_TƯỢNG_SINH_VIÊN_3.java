import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Student {
    String id;
    String name;
    String room;
    String birth;
    float point;

    public Student() {
        this.id = "";
        this.name = "";
        this.birth = "";
        this.point = 0;
    }

    public void setId(int id) {
        this.id = "B20DCCN" + String.format("%03d", id);
    }

    public void setName(String name) {
        this.name = name;
        fixName();
    }

    public void setClassroom(String room) {
        this.room = room;
    }

    public void fixName() {
        String[] s = name.split(" ");
        StringBuilder sb = new StringBuilder();
        for (String string : s) {
            if (!string.trim().isEmpty()) {
                char[] ss = string.toCharArray();
                for (int i = 0; i < ss.length; i++) {
                    if (i == 0) {
                        sb.append(Character.toUpperCase(ss[i]));
                    }
                    else {
                        sb.append(Character.toLowerCase(ss[i]));
                    }
                }
                sb.append(" ");
            }
        }
        this.name = sb.toString();
    }

    private void fix_birth() {
        String[] temp = birth.split("/");

        for (int i = 0; i < temp.length-1; i++) {
            if (temp[i].length() == 1) {
                temp[i] = "0" + temp[i];
            }
        }

        this.birth = temp[0] + "/" + temp[1] + "/" + temp[2];
    }

    public void setBirth(String birth) {
        this.birth = birth;
        fix_birth();
    }

    public void setPoint(float point) {
        this.point = point;
    }

    public float getPoint() {
        return point;
    }

    public static void order(List<Student> Students) {
        Collections.sort(Students, new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return Float.compare(o2.getPoint(), o1.getPoint());
            }
        });
}

    @Override
    public String toString() {
        return String.format("%s %s %s %s %.2f", id, name, room, birth, point);
    }
}

public class J05005_DANH_SÁCH_ĐỐI_TƯỢNG_SINH_VIÊN_3 {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        List<Student> s = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            Student stu = new Student();
            
            scan.nextLine();
            stu.setId(i+1);
            stu.setName(scan.nextLine());
            stu.setClassroom(scan.next());
            stu.setBirth(scan.next());
            stu.setPoint(scan.nextFloat());
            s.add(stu);
        }

        Student.order(s);
        for (Student student : s) {
            System.out.println(student);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}