import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Object {
    int id;
    String name;
    String classes;
    float in;
    float out;

    public Object(int id, String name, String classes, float in, float out) {
        this.id = id;
        this.name = name;
        this.classes = classes;
        this.in = in;
        this.out = out;
    }

    public float getIn() {
        return in;
    }

    public float getOut() {
        return out;
    }

    public float getReturn() {
        return out-in;
    }

    public static void order(List<Object> objs) {
        Collections.sort(objs, new Comparator<Object>() {
            @Override
            public int compare(Object o1, Object o2) {
                return Float.compare(o2.getReturn(), o1.getReturn());
            }
        } );
    }
    
    @Override
    public String toString() {
        return String.format("%d %s %s %.2f", id, name, classes, getReturn());
    }
}

public class J05010_SẮP_XẾP_DANH_SÁCH_MẶT_HÀNG {
    public static void func(Scanner scan) {
        int n = scan.nextInt();
        List<Object> objs = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            scan.nextLine();
            Object obj = new Object(i+1, scan.nextLine(), scan.nextLine(), scan.nextFloat(), scan.nextFloat());
            objs.add(obj);
        }
        Object.order(objs);

        for (Object object : objs) {
            System.out.println(object);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        func(scan);

        scan.close();
    }
}