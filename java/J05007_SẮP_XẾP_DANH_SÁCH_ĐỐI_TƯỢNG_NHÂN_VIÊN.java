import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class employ {
    String id;
    String gender;
    String name;
    int birthDay;
    int birthMonth;
    int birthYear;
    String address;
    String number;
    String signDate;

    public employ(String id, String name, String gender, String birth, String address, String number, String signDate) {
        this.id = id.trim();
        this.name = name.trim();
        this.gender = gender.trim();
        setBirth(birth.trim());
        this.address = address.trim();
        this.number = number.trim();
        this.signDate = fix_date(signDate.trim());
    }

    private void setBirth(String date) {
        String[] temp = date.split("/");

        this.birthDay = Integer.valueOf(temp[0]);
        this.birthMonth = Integer.valueOf(temp[1]);
        this.birthYear = Integer.valueOf(temp[2]);
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

    private int getBirthDay() {
        return birthDay;
    }

    private int getBirthMonth() {
        return birthMonth;
    }

    private int getBirthYear() {
        return birthYear;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %02d/%02d/%d %s %s %s", id, name, gender, birthDay, birthMonth, birthYear, address, number, signDate);
    }

    public static void order(List<employ> employs) {
        Collections.sort(employs, new Comparator<employ>() {
            @Override
            public int compare(employ o1, employ o2) {
                int y1 = o1.getBirthYear();
                int y2 = o2.getBirthYear();

                if (y1 == y2) {
                    int m1 = o1.getBirthMonth();
                    int m2 = o2.getBirthMonth();

                    if (m1 == m2) {
                        int d1 = o1.getBirthDay();
                        int d2 = o2.getBirthDay();
                        return Integer.compare(d1, d2);
                    }
                    return Integer.compare(m1, m2);
                }
                return Integer.compare(y1, y2);
            }
        });
    }
}

public class submJ05007_SẮP_XẾP_DANH_SÁCH_ĐỐI_TƯỢNG_NHÂN_VIÊNit {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        scan.nextLine();
        List<employ> ems = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            employ employ = new employ(String.format("%05d", i+1), scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine(), scan.nextLine());

            ems.add(employ);
        }
        employ.order(ems);

        for (employ employ : ems) {
            System.out.println(employ);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}