package Cryptography;

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.util.Scanner;

public class DS {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the message to sign:");
        String message = scanner.nextLine();
        scanner.close();
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
        keyGen.initialize(2048);
        KeyPair pair = keyGen.generateKeyPair();
        PrivateKey privateKey = pair.getPrivate();
        PublicKey publicKey = pair.getPublic();
        byte[] messageBytes = message.getBytes();
        Signature signature = Signature.getInstance("SHA256withRSA");
        signature.initSign(privateKey);
        signature.update(messageBytes);
        byte[] digitalSignature = signature.sign();
        System.out.println("Digital Signature: " + bytesToHex(digitalSignature));

        // Verify the signature
        signature.initVerify(publicKey);
        signature.update(messageBytes);
        boolean isCorrect = signature.verify(digitalSignature);
        System.out.println();
        System.out.println("Signature correct: " + isCorrect);
    }
    private static String bytesToHex(byte[] bytes) {
        StringBuilder builder = new StringBuilder();
        for (byte b : bytes) {
            builder.append(String.format("%02x", b));
        }
        return builder.toString();
    }
}
