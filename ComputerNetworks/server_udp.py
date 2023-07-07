import socket

# Get IP address and port from the user
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the IP address and port
server_socket.bind((ip_address, port))

print("UDP server is ready to receive messages.")

while True:
    # Receive data and the client address from the client
    data, client_address = server_socket.recvfrom(1024)
    data = data.decode()

    if not data:
        # If no data received, the client has closed the connection
        print("Client disconnected.")
        break

    print(f"Received message: {data}")

    # Send a response back to the client
    response = input("Enter your response: ")
    server_socket.sendto(response.encode(), client_address)

# Close the socket
server_socket.close()
