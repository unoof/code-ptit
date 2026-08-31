import java.util.ArrayList;
import java.util.Scanner;


class Student {
    private String id, hoten, type;
    private float[] diemcacmon;
    private double average;
    private static int stt = 1;

    public Student() {}

    public Student(String hoten, float[] diemcacmon) {
        this.id = String.format("HS%02d", stt++);
        this.hoten = hoten;
        this.diemcacmon = diemcacmon;
        setAverage(diemcacmon);
        setType();
    }

    public double getAverage() {
        return average;
    }
    public void setAverage(float[] diemcacmon) {
        float sum = (diemcacmon[0] + diemcacmon[1]) * 2;
        for (int i = 2; i < diemcacmon.length; i++) {
            sum += diemcacmon[i];
        }
        sum /= 12;
        average = Math.round((sum+0.01) * 10.0) / 10.0;
    }

    public void setType() {
        if (average >= 9) this.type = "XUAT SAC";
        else if (average >= 8) this.type = "GIOI";
        else if (average >= 7) this.type = "KHA";
        else if (average >= 5) this.type = "TB";
        else this.type = "YEU";
    }

    @Override
    public String toString() {
        return String.format("%s %s %.1f %s", id, hoten, average, type);
    }
}

public class J05018_BẢNG_ĐIỂM_HỌC_SINH {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        ArrayList<Student> studentList = new ArrayList<>();

        while (t-- > 0) {
            sc.nextLine();
            String hoten = sc.nextLine();
            float[] diemcacmon = new float[10];
            for (int i = 0; i < 10; i++) {
                diemcacmon[i] = sc.nextFloat();
            }
            studentList.add(new Student(hoten, diemcacmon));
        }

        studentList.sort((s1, s2) -> Double.compare(s2.getAverage(), s1.getAverage()));

        for (Student e : studentList) {
            System.out.println(e);
        }

        sc.close();
    }
}