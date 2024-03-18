package Cryptography;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.*;

public class DES {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
        SecretKey secretKey = keyGenerator.generateKey();
        byte[] keyBytes = secretKey.getEncoded();
        System.out.print("Enter a string: ");
        String originalString = sc.next();
        System.out.println("Original: " + originalString);
        byte[] encrypted = encryptDecrypt(originalString.getBytes(), keyBytes,
                Cipher.ENCRYPT_MODE);
        System.out.println("Encrypted: " + new String(encrypted));
        byte[] decrypted = encryptDecrypt(encrypted, keyBytes, Cipher.DECRYPT_MODE);
        System.out.println("Decrypted: " + new String(decrypted));
        sc.close();
    }

    private static byte[] encryptDecrypt(byte[] inputBytes, byte[] keyBytes, int mode)
            throws Exception {
        SecretKeySpec secretKeySpec = new SecretKeySpec(keyBytes,
                "DES");
        Cipher cipher = Cipher.getInstance("DES");
        cipher.init(mode, secretKeySpec);
        return cipher.doFinal(inputBytes);
    }
}