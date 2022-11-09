import java.util.*;

class PasswordException extends Exception {
    public PasswordException(String message) {
        super(message);
    }
}

public class ExceptionTest6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String pwd = sc.next();
        try {
            PasswordChecker(pwd);
        } catch (PasswordException e) {
            System.out.println("Invalid Password");
            System.out.println(e.getMessage());
        }
        sc.close();
    }

    public static void PasswordChecker(String pwd) throws PasswordException {
        int l = pwd.length();

        if (l < 8)
            throw new PasswordException("Password must contain 8 characters");
        else if (l > 15)
            throw new PasswordException("Password must be less than 15 characters");

        if (pwd.contains(" ")) {
            throw new PasswordException("Password should not contain a space");
        }
        if (!(pwd.contains("@") || pwd.contains("#")
                || pwd.contains("!") || pwd.contains("~")
                || pwd.contains("$") || pwd.contains("%")
                || pwd.contains("^") || pwd.contains("&")
                || pwd.contains("*") || pwd.contains("(")
                || pwd.contains(")") || pwd.contains("-")
                || pwd.contains("+") || pwd.contains("/")
                || pwd.contains(":") || pwd.contains(".")
                || pwd.contains(",") || pwd.contains("<")
                || pwd.contains(">") || pwd.contains("?")
                || pwd.contains("|"))) {
            throw new PasswordException("Password must contain a special character");
        }

        if (true) {
            int count = 0;

            for (int i = 65; i <= 90; i++) {

                char c = (char) i;

                String str1 = Character.toString(c);
                if (pwd.contains(str1)) {
                    count = 1;
                }
            }
            if (count == 0) {
                throw new PasswordException("Password must have at least one uppercase character(A-Z)");
            }
        }

        if (true) {
            int count = 0;
            for (int i = 90; i <= 122; i++) {
                char c = (char) i;
                String str2 = Character.toString(c);

                if (pwd.contains(str2)) {
                    count = 1;
                }
            }
            if (count == 0) {
                throw new PasswordException("Password must have at least one lowercase character(a-z)");
            }
        }

        if (true) {
            System.out.println("Password is Valid");
        }
    }
}
