package Cryptography;

import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;

public class SHA {
    public static void main(String[] args) {
        String message = "The quick brown fox jumps over the lazy dog";
        String secretKey = "secret";

        try {
            String hmacSHA256 = generateHmacSHA256(message, secretKey);
            System.out.println("HMAC-SHA256: " + hmacSHA256);
        } catch (NoSuchAlgorithmException | InvalidKeyException e) {
            System.err.println("Error generating HMAC-SHA256: " + e.getMessage());
        }
    }

    public static String generateHmacSHA256(String message, String secretKey)
            throws NoSuchAlgorithmException, InvalidKeyException {
        // Create a new instance of Mac with HMAC-SHA256 algorithm
        Mac mac = Mac.getInstance("HmacSHA256");

        // Convert the secret key to a SecretKeySpec
        SecretKeySpec secretKeySpec = new SecretKeySpec(secretKey.getBytes(), "HmacSHA256");

        // Initialize the Mac instance with the secret key
        mac.init(secretKeySpec);

        // Perform the HMAC-SHA256 operation on the input message
        byte[] hmacBytes = mac.doFinal(message.getBytes());

        // Convert the result into a hexadecimal string
        StringBuilder hexString = new StringBuilder();
        for (byte b : hmacBytes) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }

        return hexString.toString();
    }
}