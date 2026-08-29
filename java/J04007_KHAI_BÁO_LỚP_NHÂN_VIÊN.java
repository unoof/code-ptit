import java.util.Scanner;

class employ {
    String id;
    String gender;
    String name;
    String birth;
    String address;
    String number;
    String signDate;

    public employ(String name, String gender, String birth, String address, String number, String signDate) {
        this.id = "00001";
        this.name = name;
        this.gender = gender;
        this.birth = birth;
        this.address = address;
        this.number = number;
        this.signDate = signDate;

        this.birth = fix_date(this.birth);
        this.signDate = fix_date(this.signDate);
    }

    private String fix_date(String date) {
        String[] temp = date.split("/");

        for (int i = 0; i < temp.length-1; i++) {
            if (temp[i].length() == 1) {
                temp[i] = "0" + temp[i];
            }
        }

        return temp[0] + "/" + temp[1] + "/" + temp[2];
    }

    public void out() {
        System.out.printf("%s %s %s %s %s %s %s", this.id, this.name, this.gender, this.birth, this.address, this.number, this.signDate);
    }
}

public class J04007_KHAI_BÁO_LỚP_NHÂN_VIÊN {
    public static void func(Scanner scan) {
        employ sj = new employ(scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine());

        sj.out();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}