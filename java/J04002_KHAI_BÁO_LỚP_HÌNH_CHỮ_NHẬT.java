import java.util.Scanner;

class Rectange {
    double width;
    double height;
    String color = null;

    public Rectange() {
        this.width = 1;
        this.height = 1;
    }

    public Rectange(double width, double height, String color) {
        this.color = color;
        this.width = width;
        this.height = height;
    }

    public double getWidth() {
        return this.width;
    }

    public double getHeight() {
        return this.height;
    }

    private String normalise() {
        String temp = "";
        for (int i = 0; i < this.color.toCharArray().length; i++) {
            if (i == 0) {
                temp += Character.toUpperCase(this.color.charAt(i));
            }
            else {
                temp += Character.toLowerCase(this.color.charAt(i));
            }
        }
        return temp;
    }

    public String getColor() {
        return this.color != null ? normalise() : "No color";
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public double findArea() {
        return this.width*this.height;
    }

    public double  findPerimeter() {
        return this.width*2 + this.height*2;
    }
}


public class J04002_KHAI_BÁO_LỚP_HÌNH_CHỮ_NHẬT {
    public static void func(Scanner scan) {
        Rectange rec = new Rectange(scan.nextDouble(), scan.nextDouble(), scan.next());

        if (rec.height > 0 && rec.width > 0) {
            System.out.printf("%d %d %s", (int) rec.findPerimeter(), (int) rec.findArea(), rec.getColor());
        }
        else {
            System.out.println("INVALID");
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}