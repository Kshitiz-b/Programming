import socket

# Get IP address and port from the user
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))

# Create a TCP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
client_socket.connect((ip_address, port))
print("Connected to server.")

while True:
    # Send a message to the server
    message = input("Enter your message: ")
    client_socket.send(message.encode())

    if message.lower() == "bye":
        # If the message is "bye", close the connection
        print("Closing the connection.")
        break

    # Receive a response from the server
    response = client_socket.recv(1024).decode()
    print(f"Server response: {response}")

# Close the socket
client_socket.close()
