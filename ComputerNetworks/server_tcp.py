import socket

# Get IP address and port from the user
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))

# Create a TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the IP address and port
server_socket.bind((ip_address, port))

# Listen for incoming connections
server_socket.listen(1)

print("TCP server is ready to receive messages.")

# Accept a client connection
client_socket, client_address = server_socket.accept()
print(f"Connected to client: {client_address}")

while True:
    # Receive data from the client
    data = client_socket.recv(1024).decode()

    if not data:
        # If no data received, the client has closed the connection
        print("Client disconnected.")
        break

    print(f"Received message: {data}")

    # Send a response back to the client
    response = input("Enter your response: ")
    client_socket.send(response.encode())

# Close the sockets
client_socket.close()
server_socket.close()
