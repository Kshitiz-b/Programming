import java.util.Scanner;

class BalanceException extends Exception {
    public BalanceException(String message) {
        super(message);
    }
}

public class ExceptionTest5 {
    public static void main(String[] args) {
        int balance;

        try {
            Scanner sc = new Scanner(System.in);
            balance = sc.nextInt();
            updateBalance(balance);
            sc.close();
        } catch (BalanceException ex) {
            System.out.println("Caught BalanceException");
        } catch (NumberFormatException ex) {
            System.out.println("Caught NumberFormatException");
        } catch (Exception ex) {
            System.out.println("Some other exception caught");
        }

    }

    public static void updateBalance(int balance) throws BalanceException {
        if (balance < 0)
            throw new BalanceException("Account balance cannot be less than Zero");
        else
            System.out.println("No Exception occured");
    }
}
