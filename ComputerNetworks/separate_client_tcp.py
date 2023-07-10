import socket


def tcp_client(port):
    host = input("Enter the server IP address: ")

    # Create a TCP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect to the server
    client_socket.connect((host, port))
    print(f"Connected to server: {host}:{port}")

    while True:
        # Send a message to the server
        message = input("Client: ")
        client_socket.sendall(message.encode())

        # Receive a response from the server
        response = client_socket.recv(1024).decode()

        if not response:
            # If no response received, the server has disconnected
            print("Server has disconnected.")
            break

        print(f"Server: {response}")

    # Close the socket
    client_socket.close()


# Get the port number from the user
port = int(input("Enter the port number: "))
tcp_client(port)
