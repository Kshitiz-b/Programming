import java.util.*;

public class palDrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the String:");
        String str = sc.next();
        str = str.toLowerCase();
        StringBuffer strrev = new StringBuffer(str);
        strrev.reverse();
        String str1 = strrev.toString();

        if (str.equals(str1)) {
            System.out.println("is Palindrome");
        } else
            System.out.println("Not Palindrome");

        sc.close();
    }
}