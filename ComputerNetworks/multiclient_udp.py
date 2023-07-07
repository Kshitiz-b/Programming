import socket

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Get server IP address and port from the user
server_ip = input("Enter server IP address: ")
server_port = int(input("Enter server port number: "))

# Connect to the server
server_address = (server_ip, server_port)
print("Connected to server.")

# Initialize the client name
client_name = input("Enter client name: ")

while True:
    # Prompt the user to enter a message
    message = input("Enter your message (or 'exit' to quit): ")

    if message == 'exit':
        break

    # Send the message to the server along with the client name
    client_socket.sendto(f"{client_name}:{message}".encode(), server_address)

    # Receive the response from the server
    response, _ = client_socket.recvfrom(1024)
    response = response.decode()

    print(f"Server response: {response}")

# Close the socket
client_socket.close()
