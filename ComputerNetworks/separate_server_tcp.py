import socket


def tcp_server(port):
    host = ''  # Automatically determines the IP address of the machine

    # Create a TCP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to a specific address and port
    server_socket.bind((host, port))

    # Listen for incoming connections
    server_socket.listen(1)
    print(f"TCP server is listening on port {port}")

    # Accept a client connection
    client_socket, client_address = server_socket.accept()
    print(f"Connected to client: {client_address}")

    while True:
        # Receive data from the client
        data = client_socket.recv(1024).decode()

        if not data:
            # If no data received, the client has disconnected
            print("Client has disconnected.")
            break

        print(f"Client: {data}")

        # Send a response back to the client
        response = input("Server: ")
        client_socket.sendall(response.encode())

    # Close the socket
    client_socket.close()
    server_socket.close()


# Get the port number from the user
port = int(input("Enter the port number: "))
tcp_server(port)
