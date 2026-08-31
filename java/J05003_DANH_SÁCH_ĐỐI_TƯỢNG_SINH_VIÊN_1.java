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
    }

    public void setClassroom(String room) {
        this.room = room;
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

    public void out() {
        System.out.printf("%s %s %s %s %.2f\n", id, name, room, birth, point);
    }
}

public class J05003_DANH_SÁCH_ĐỐI_TƯỢNG_SINH_VIÊN_1 {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        
        for (int i = 0; i < n; i++) {
            Student stu = new Student();
            
            scan.nextLine();
            stu.setId(i+1);
            stu.setName(scan.nextLine());
            stu.setClassroom(scan.next());
            stu.setBirth(scan.next());
            stu.setPoint(scan.nextFloat());
    
            stu.out();
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}