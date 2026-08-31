import java.util.Scanner;

class Student {
    String id;
    String name;
    String room;
    String birth;
    float point;

    public Student() {
        this.id = "B20DCCN001";
        this.name = "";
        this.birth = "";
        this.point = 0;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setClassroom(String room) {
        this.room = room;
    }

    private void fix_birth() {
        String[] temp = this.birth.split("/");

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

    public void out() {
        System.out.printf("%s %s %s %s %.2f", this.id, this.name, this.room, this.birth, this.point);
    }
}

public class J04006_KHAI_BÁO_LỚP_SINH_VIÊN {
    public static void func(Scanner scan) {
        Student stu = new Student();

        stu.setName(scan.nextLine());
        stu.setClassroom(scan.next());
        stu.setBirth(scan.next());
        stu.setPoint(scan.nextFloat());

        stu.out();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}