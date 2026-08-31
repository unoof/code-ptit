import java.util.Scanner;

class employ {
    String id;
    String gender;
    String name;
    String birth;
    String address;
    String number;
    String signDate;

    public employ(String id, String name, String gender, String birth, String address, String number, String signDate) {
        this.id = id.trim();
        this.name = name.trim();
        this.gender = gender.trim();
        this.birth = birth.trim();
        this.address = address.trim();
        this.number = number.trim();
        this.signDate = signDate.trim();

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

    @Override
    public String toString() {
        return String.format("%s %s %s %s %s %s %s", this.id, this.name, this.gender, this.birth, this.address, this.number, this.signDate);
    }
}


public class J05006_DANH_SÁCH_ĐỐI_TƯỢNG_NHÂN_VIÊN {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        scan.nextLine();
        
        for (int i = 0; i < n; i++) {
            employ employ = new employ(String.format("%05d", i+1), scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine());

            System.out.println(employ);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}