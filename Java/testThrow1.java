import java.util.*;
public class testThrow1 {
    public static void Validate(int age) {
        if (age < 18) {
            throw new ArithmeticException("Person is not eligible to vote.");
        } else {
            System.out.println("Person is eligible to vote.");
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the age:");
            int age = sc.nextInt();
            Validate(age);
        }
    }
}
