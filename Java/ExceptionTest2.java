import java.util.Scanner;

public class ExceptionTest2 {
    public static void main(String[] args) {
        try {
            methodA();
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException caught...\n"+e);
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
