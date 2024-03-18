package Cryptography;

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.Base64;
import javax.crypto.Cipher;

public class RSA {

    private PublicKey publicKey;
    private PrivateKey privateKey;

    public RSA() {
        try {
            // Initialize the KeyPairGenerator
            KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
            keyGen.initialize(2048);
            // Generate the KeyPair
            KeyPair pair = keyGen.generateKeyPair();
            // Get the public and private key
            publicKey = pair.getPublic();
            privateKey = pair.getPrivate();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }

    public String encrypt(String message) throws Exception {
        // Initialize the cipher with the public key for encryption
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedBytes = cipher.doFinal(message.getBytes());
        // Encode the encrypted bytes to Base64 to get a string
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    public String decrypt(String encryptedMessage) throws Exception {
        // Decode the encrypted message from Base64
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedMessage);
        // Initialize the cipher with the private key for decryption
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        // Convert the decrypted bytes back to a string
        return new String(decryptedBytes);
    }

    public static void main(String[] args) {
        try {
            RSA rsa = new RSA();
            String originalMessage = "Kshitiz Bhargava";
            System.out.println("Original Message: " + originalMessage);

            String encryptedMessage = rsa.encrypt(originalMessage);
            System.out.println("Encrypted Message: " + encryptedMessage);

            String decryptedMessage = rsa.decrypt(encryptedMessage);
            System.out.println("Decrypted Message: " + decryptedMessage);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
