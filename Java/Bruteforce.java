import java.util.*;

public class Bruteforce {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the password to crack: ");
        String passwordToCrack = scanner.nextLine();

        long startTime = System.currentTimeMillis();
        int tries = bruteForce(passwordToCrack);
        long endTime = System.currentTimeMillis();
        long executionTime = endTime - startTime;

        if (tries > 0) {
            System.out.println("\nPassword cracked: " + passwordToCrack);
            System.out.println("\nNumber of tries: " + tries);
        } else {
            System.out.println("\nPassword not cracked.");
        }

        System.out.println("Execution time: " + executionTime + " milliseconds");
        scanner.close();
    }

    private static int bruteForce(String passwordToCrack) {
        String characters = generateCharacterSet();
        char[] charSet = characters.toCharArray();
        int passwordLength = passwordToCrack.length();
        int totalCharacters = charSet.length;
        int tries = 0;

        for (int length = 1; length <= passwordLength; length++) {
            tries += Math.pow(totalCharacters, length);
            if (bruteForceRec(charSet, passwordToCrack, new char[length], 0, length - 1)) {
                return tries;
            }
        }

        return 0;
    }

    private static boolean bruteForceRec(char[] charSet, String passwordToCrack, char[] attempt, int currentIndex,
            int maxIndex) {
        if (currentIndex > maxIndex) {
            String currentAttempt = new String(attempt);
            if (currentAttempt.equals(passwordToCrack)) {
                return true;
            }
            return false;
        }

        for (int i = 0; i < charSet.length; i++) {
            attempt[currentIndex] = charSet[i];
            if (bruteForceRec(charSet, passwordToCrack, attempt, currentIndex + 1, maxIndex)) {
                return true;
            }
        }

        return false;
    }

    private static String generateCharacterSet() {
        StringBuilder characters = new StringBuilder();

        for (char c = 'a'; c <= 'z'; c++) {
            characters.append(c);
        }

        for (char c = 'A'; c <= 'Z'; c++) {
            characters.append(c);
        }

        for (char c = '0'; c <= '9'; c++) {
            characters.append(c);
        }

        characters.append("!@#$%^&*()_-+=<>?");

        return characters.toString();
    }
}
