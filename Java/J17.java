public class J17 {
    public static void main(String[] args) {
        try {
            int data = 100/0;
            System.out.println(data);
        }
        catch(ArithmeticException e) {
            System.out.println(e);
        }
        System.out.println("The rest of the code...");
    }
}
