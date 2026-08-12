import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class HELLOFILE_HELLO_FILE {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scan = new Scanner(new File("Hello.txt"));
        while (scan.hasNextLine()) {
            String data = scan.nextLine();
            System.out.println(data);
        }
        scan.close();
    }
}