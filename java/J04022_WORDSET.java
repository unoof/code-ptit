import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class WordSet {
    String[] A;

    public WordSet(String A) {
        this.A = A.split(" ");
        for (int i = 0; i < this.A.length; i++) {
            if (!this.A[i].trim().isEmpty()) {
                this.A[i] = this.A[i].trim().toLowerCase();
            }
        }

        Arrays.sort(this.A);
    }

    public WordSet(String[] A) {
        this.A = A;
        for (int i = 0; i < this.A.length; i++) {
            if (!this.A[i].trim().isEmpty()) {
                this.A[i] = this.A[i].trim().toLowerCase();
            }
        }

        Arrays.sort(this.A);
    }

    public WordSet union(WordSet s2) {
        List<String> ans = new ArrayList<>();

        int i = 0;
        int j = 0;
        String last = "";
        while (i < A.length && j < s2.A.length) {
            int temp = A[i].compareTo(s2.A[j]);
            if (temp > 0) {
                if (!last.equals(s2.A[j])) {
                    ans.add(s2.A[j]);
                    last = s2.A[j];
                }
                j++;
            }
            else if (temp < 0) {
                if (!last.equals(A[i])) {
                    ans.add(A[i]);
                    last = A[i];
                }
                i++;
            }
            else {
                if (!last.equals(A[i])) {
                    ans.add(A[i]);
                    last = A[i];
                }
                i++; j++;
            }
        }

        while (i < A.length) {
            if (!last.equals(A[i])) {
                ans.add(A[i]);
                last = A[i];
            }
            i++;
        }
        while (j < s2.A.length) {
            if (!last.equals(s2.A[j])) {
                ans.add(s2.A[j]);
                last = s2.A[j];
            }
            j++;
        }
        return new WordSet(ans.toArray(new String[0]));
    }

    public WordSet intersection(WordSet s2) {
        List<String> ans = new ArrayList<>();

        int i = 0;
        int j = 0;
        String last = "";
        while (i < A.length && j < s2.A.length) {
            int temp = A[i].compareTo(s2.A[j]);
            if (temp > 0) {
                j++;
            }
            else if (temp < 0) {
                i++;
            }
            else {
                if (!last.equals(A[i])) {
                    ans.add(A[i]);
                    last = A[i];
                }
                i++; j++;
            }
        }

        return new WordSet(ans.toArray(new String[0]));   
    }

    @Override
    public String toString() {
        return String.join(" ", A);
    }
}

public class J04022_WORDSET {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        WordSet s1 = new WordSet(in.nextLine());
        WordSet s2 = new WordSet(in.nextLine());
        System.out.println(s1.union(s2));
        System.out.println(s1.intersection(s2));
    }
}
