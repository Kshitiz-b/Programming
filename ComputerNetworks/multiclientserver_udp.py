import socket
import threading

# Get IP address and port from the user
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the IP address and port
server_socket.bind((ip_address, port))

print("UDP server is ready to receive messages.")

# Dictionary to store client information
clients = {"Manvendra", "Moulik"}

def handle_client_message(data, client_address):
    # Extract the client name and message from the received data
    client_name, message = data.split(":", 1)

    # Check if the client name exists in the clients dictionary
    if client_name in clients:
        print(f"Received message from {client_name}: {message}")

        # Send a response back to the client
        response = input("Enter your response: ")
        server_socket.sendto(response.encode(), client_address)

    else:
        print(f"Unknown client: {client_name}")
        clients[client_name] = client_address

def receive_messages():
    while True:
        # Receive data and the client address from the client
        data, client_address = server_socket.recvfrom(1024)
        data = data.decode()

        if not data:
            # If no data received, the client has closed the connection
            print("Client disconnected.")
            break

        # Handle the client message in a new thread
        threading.Thread(target=handle_client_message, args=(data, client_address)).start()

# Start receiving messages in a separate thread
receive_thread = threading.Thread(target=receive_messages)
receive_thread.start()

# Wait for the receive thread to finish
receive_thread.join()

# Close the socket
server_socket.close()
