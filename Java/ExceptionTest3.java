import java.util.Scanner;

public class ExceptionTest3 {
    public static void main(String[] args) {
        try {
            methodA();
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException caught...");
            e.printStackTrace();
        }
    }

    public static void methodA() throws ArithmeticException {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        sc.close();

        if (a == 0 || b == 0)
            throw new ArithmeticException();
        else {
            int div = a / b;
            System.out.println("The div is " + div);
        }
    }

}
