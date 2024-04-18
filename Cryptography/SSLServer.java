package Cryptography;

import javax.net.ssl.SSLServerSocketFactory;
import javax.net.ssl.SSLServerSocket;
import javax.net.ssl.SSLSocket;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class SSLServer {
    public static void main(String[] args) {
        int port = 8443; // Port number
        try {
            SSLServerSocketFactory factory = (SSLServerSocketFactory) SSLServerSocketFactory.getDefault();
            SSLServerSocket serverSocket = (SSLServerSocket) factory.createServerSocket(port);

            System.out.println("SSL Server Started");
            while (true) {
                try (SSLSocket sslSocket = (SSLSocket) serverSocket.accept()) {
                    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(sslSocket.getOutputStream()));
                    writer.write("Hello from SSL Server!\n");
                    writer.flush();
                    System.out.println("Greeting sent to client.");
                } catch (Exception e) {
                    System.err.println("Server connection error: " + e.getMessage());
                }
            }
        } catch (Exception e) {
            System.err.println("Server could not start: " + e.getMessage());
        }
    }
}

