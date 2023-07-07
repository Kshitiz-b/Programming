import socket

# Get IP address and port from the user
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    # Send a message to the server
    message = input("Enter your message: ")
    client_socket.sendto(message.encode(), (ip_address, port))

    if message.lower() == "bye":
        # If the message is "bye", close the connection
        print("Closing the connection.")
        break

    # Receive a response from the server
    response, server_address = client_socket.recvfrom(1024)
    response = response.decode()
    print(f"Server response: {response}")

# Close the socket
client_socket.close()
