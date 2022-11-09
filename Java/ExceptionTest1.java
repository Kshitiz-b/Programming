// Unchecked
public class ExceptionTest1 {
    public static void main(String[] args) {
        int a, b, sum;
        try {
            a = Integer.parseInt(args[0]);
            b = Integer.parseInt(args[1]);
            sum = a+b;
            System.out.println("Sum is " + sum);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Insufficient no of args");
        }
    }
}
