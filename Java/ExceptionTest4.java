import java.util.*;
import java.io.*;

public class ExceptionTest4 {
    public static void main(String[] args) {
        try {
            methodA();
            Scanner in1 = new Scanner(new File("D:/OneDrive/Documents/Programming/Java/file1.txt"));

            in1.close();

        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException caught...");
        } catch (FileNotFoundException e) {
            System.out.println("FileNotFoundException caught...");
        } catch (Exception e) {
            System.out.println("A new type of exception has occured..."); // this exception is of the highest type so it will catch all exceptions
        }
    }

    public static void methodA() {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int div = a / b;
        System.out.println("The div is " + div);
        sc.close();
    }
}
