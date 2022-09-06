// program to check Strobogrammatic Number
import java.util.Scanner;

public class Stbr {
    static boolean isStbr(String num) {
        int len = num.length();
        for (int i = 0; i < num.length(); i++) {
            switch (num.charAt(i)) {
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                    return false;
                case 6:
                    if ('9' != num.charAt(len - 1 - i))
                        return false;
                    break;
                case 9:
                    if ('6' != num.charAt(len - 1 - i))
                        return false;
                    break;
                case 1:
                case 8:
                case 0:
                    if (num.charAt(i) != num.charAt(len - 1 - i))
                        return false;
                    break;

            }
        }
        return true;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            String num = sc.next();

            if (isStbr(num))
                System.out.println(num + " is Strobogrammatic");
        }

    }
}