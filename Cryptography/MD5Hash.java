package Cryptography;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5Hash {
    public static void main(String[] args) {
        String message = "This is a message to hash";
        String md5Hash = getMD5Hash(message);
        if (md5Hash != null) {
            System.out.println("MD5-MAC: " + md5Hash);
        } else {
            System.out.println("Error generating MD5 hash.");
        }
    }

    public static String getMD5Hash(String message) {
        try {
            // Create a MessageDigest instance for MD5
            MessageDigest digest = MessageDigest.getInstance("MD5");
            
            // Perform the hash calculation
            byte[] hashBytes = digest.digest(message.getBytes());
            
            // Convert the byte array to a hexadecimal string
            StringBuilder hexString = new StringBuilder();
            for (byte b : hashBytes) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            System.err.println("MD5 algorithm not found.");
            return null;
        }
    }
}