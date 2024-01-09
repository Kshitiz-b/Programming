package Cryptography;

import java.util.Scanner;

public class CrackingCaesar {
    public static void Decoder(Scanner sc) {
        System.out.println("Enter a string: ");
        String input = sc.nextLine();

        for (int k = 0; k < 26; k++) {
            String output = "";
            for (int i = 0; i < input.length(); i++) {
                char ch = input.charAt(i);
                if (Character.isLetter(ch)) {
                    char base = Character.isUpperCase(ch) ? 'A' : 'a';
                    output += (char) ((ch - base - k + 26) % 26 + base); // Ensure positive result
                } else if (Character.isDigit(ch)) {
                    int base = 48;
                    output += (char) ((ch - base - k + 10) % 10 + base);
                } else {
                    output += ch;
                }
            }
            System.out.println(k + " : " + output);
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Decoder(sc);
    }
}
