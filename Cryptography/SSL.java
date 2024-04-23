package Cryptography;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class SSL {

    public static void main(String[] args) {
        Thread serverThread = new Thread(SSL::runServer);
        Thread clientThread = new Thread(() -> {
            try {
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                System.out.println("Client interrupted before starting.");
            }
            runClient();
        });

        serverThread.start();
        clientThread.start();
    }

    private static void runServer() {
        try (ServerSocket serverSocket = new ServerSocket(8443)) {
            System.out.println("Server started, waiting for a connection...");

            try (Socket clientSocket = serverSocket.accept();
                 BufferedReader reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                 PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true)) {
                
                System.out.println("Client connected, waiting for messages...");
                String line;
                while ((line = reader.readLine()) != null) {
                    System.out.println("Server received: " + line);
                    writer.println("Echo from server: " + line);
                }
            }
        } catch (IOException e) {
            System.out.println("Server Exception: " + e.getMessage());
        }
    }

    private static void runClient() {
        try (Socket socket = new Socket("localhost", 8443);
             PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
            
            System.out.println("Connected to server. Sending a message...");
            writer.println("Hello from client");

            String response = reader.readLine();
            System.out.println("Client received: " + response);
        } catch (IOException e) {
            System.out.println("Client Exception: " + e.getMessage());
        }
    }
}