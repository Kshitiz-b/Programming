public class J8 {
    public static void main(String[] args) {
        int x = 13;
        int i;
        int count = 0;

        for (i = 1; i <= x; i++) {
            if (x % i == 0) {
                count += 1;
            }
        }

        if (count > 2) {
            System.out.println("The given number " + x + " is not prime");
        } 
        else
            System.out.println("The given number " + x + " is prime");
    }
}
