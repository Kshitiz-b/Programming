import java.util.Scanner;

class InvalidUsernameException extends Exception {
    int usernameConditionViolated = 0;

    public InvalidUsernameException(int conditionViolated) {
        super("Kindly Enter a Valid mail id.");
        usernameConditionViolated = conditionViolated;
    }

    public String printMessage() {
        switch (usernameConditionViolated) {

            // case 1:
            // return ("Username length should be between 8 to 15 characters");
            case 2:
                return ("Username should not contain any space");
            case 3:
                return ("Username should not contain any special character");
        }
        return ("");
    }
}

class InvalidPasswordException extends Exception {

    int passwordConditionViolated = 0;

    public InvalidPasswordException(int conditionViolated) {
        super("Invalid Password: ");
        passwordConditionViolated = conditionViolated;
    }

    public String printMessage() {
        switch (passwordConditionViolated) {

            case 1:
                return ("Password length should be"
                        + " between 8 to 15 characters");

            case 2:
                return ("Password should not"
                        + " contain any space");

            case 3:
                return ("Password should contain"
                        + " at least one digit(0-9)");

            // case 4:
            //     return ("Password should contain at "
            //             + "least one special character");
            // case 5:
            //     return ("Password should contain at"
            //             + " least one uppercase letter(A-Z)");
            // case 6:
            //     return ("Password should contain at"
            //             + " least one lowercase letter(a-z)");

        }

        return ("");
    }
}

class PasswordValidator extends Validator {

    public static void isValid(String password) throws InvalidPasswordException {

        if (password.length() < 8) {
            throw new InvalidPasswordException(1);
        }

        if (password.contains(" ")) {
            throw new InvalidPasswordException(2);
        }
        if (true) {
            int count = 0;

            for (int i = 0; i <= 9; i++) {
                String str1 = Integer.toString(i);

                if (password.contains(str1)) {
                    count = 1;
                }
            }
            if (count == 0) {
                throw new InvalidPasswordException(3);
            }
        }

        // if (!(password.contains("@") || password.contains("#")
        //         || password.contains("!") || password.contains("~")
        //         || password.contains("$") || password.contains("%")
        //         || password.contains("^") || password.contains("&")
        //         || password.contains("*") || password.contains("(")
        //         || password.contains(")") || password.contains("-")
        //         || password.contains("+") || password.contains("/")
        //         || password.contains(":") || password.contains(".")
        //         || password.contains(", ") || password.contains("<")
        //         || password.contains(">") || password.contains("?")
        //         || password.contains("|"))) {
        //     throw new InvalidPasswordException(4);
        // }

        // if (true) {
        //     int count = 0;

        //     for (int i = 65; i <= 90; i++) {

        //         char c = (char) i;

        //         String str1 = Character.toString(c);
        //         if (password.contains(str1)) {
        //             count = 1;
        //         }
        //     }
        //     if (count == 0) {
        //         throw new InvalidPasswordException(5);
        //     }
        // }

        // if (true) {
        //     int count = 0;
        //     for (int i = 90; i <= 122; i++) {
        //         char c = (char) i;
        //         String str1 = Character.toString(c);

        //         if (password.contains(str1)) {
        //             count = 1;
        //         }
        //     }
        //     if (count == 0) {
        //         throw new InvalidPasswordException(6);
        //     }
        // }

    }

}

class UsernameValidator extends Validator {
    public static void isValid(String username) throws InvalidUsernameException {

        if (!((username.length() >= 8) && (username.length() <= 15))) {
            throw new InvalidUsernameException(1);
        }

        if (username.contains(" ")) {
            throw new InvalidUsernameException(2);
        }

        if ((username.contains("@") || username.contains("#")
                || username.contains("!") || username.contains("~")
                || username.contains("$") || username.contains("%")
                || username.contains("^") || username.contains("&")
                || username.contains("*") || username.contains("(")
                || username.contains(")") || username.contains("-")
                || username.contains("+") || username.contains("/")
                || username.contains(":") || username.contains(".")
                || username.contains(", ") || username.contains("<")
                || username.contains(">") || username.contains("?")
                || username.contains("|"))) {
            throw new InvalidUsernameException(3);
        }

    }
}

public class Validator {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            // System.out.println("Enter the password: ");
            String password1 = sc.next();
            String username1 = sc.next();
            try {
                UsernameValidator.isValid(username1);
            } catch (InvalidUsernameException m) {
                System.out.print(m.getMessage());
            }
            try {
                // System.out.println("Is Password " + password1 + " valid?");

                PasswordValidator.isValid(password1);
                System.out.println("Valid Credentials.");
            } catch (InvalidPasswordException e) {
                System.out.print(e.getMessage());
                System.out.println(e.printMessage());
            }
            // System.out.println("Enter the username: ");

            // try {
            // //System.out.println("Is Username " + username1 + " valid?");

            // System.out.println("Valid Username");
            // } catch (InvalidUsernameException m) {
            // System.out.print(m.getMessage());
            // //System.out.println(m.printMessage());
            // }
        }

    }
}
