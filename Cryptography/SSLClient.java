package Cryptography;

import javax.net.ssl.SSLSocketFactory;
import javax.net.ssl.SSLSocket;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SSLClient {
    public static void main(String[] args) {
        String host = "localhost";
        int port = 8443;
        try {
            SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
            try (SSLSocket sslSocket = (SSLSocket) factory.createSocket(host, port)) {
                sslSocket.startHandshake();

                BufferedReader reader = new BufferedReader(new InputStreamReader(sslSocket.getInputStream()));
                String line = reader.readLine();
                System.out.println("Message from server: " + line);
            } catch (Exception e) {
                System.err.println("Client error: " + e.getMessage());
            }
        } catch (Exception e) {
            System.err.println("Could not connect to server: " + e.getMessage());
        }
    }
}

