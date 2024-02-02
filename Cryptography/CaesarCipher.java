package Cryptography;

import java.util.Scanner;

public class CaesarCipher {

    public static String Encode(Scanner sc) {
        System.out.println("Enter a word: ");
        String input = sc.nextLine();
        System.out.println("Enter key values: ");
        int k = sc.nextInt();
        sc.nextLine(); 

        String output = "";
        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if (Character.isLetter(ch)) { 
                char base = Character.isUpperCase(ch) ? 'A' : 'a'; 
                output += (char) ((ch - base + k) % 26 + base);
            } else {
                output += ch;
            }
        }
        return output;
    }

    public static String Decode(Scanner sc) {
        System.out.println("Enter a word: ");
        String input = sc.nextLine();
        System.out.println("Enter key values: ");
        int k = sc.nextInt();
        sc.nextLine(); 

        String output = "";
        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if (Character.isLetter(ch)) {
                char base = Character.isUpperCase(ch) ? 'A' : 'a';
                output += (char) ((ch - base - k + 26) % 26 + base);
            } else {
                output += ch;
            }
        }
        return output;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        do {
            System.out.println("Enter 1 for Encode or 2 for Decode or 0 to exit");
            choice = sc.nextInt();
            sc.nextLine(); 
            switch (choice) {
                case 1:
                    String encodedCipher = Encode(sc);
                    System.out.println(encodedCipher);
                    break;

                case 2:
                    String decodedCipher = Decode(sc);
                    System.out.println(decodedCipher);
                    break;

                default:
                    break;
            }
        } while (choice != 0);
    }
}