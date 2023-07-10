import socket

def udp_server(port):
    host = ''  # Automatically determines the IP address of the machine

    # Create a UDP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Bind the socket to a specific address and port
    server_socket.bind((host, port))

    print(f"UDP server is listening on port {port}")

    while True:
        # Receive data from the client
        data, client_address = server_socket.recvfrom(1024)
        print(f"Received data from {client_address}: {data.decode()}")

        # Send a response back to the client
        response = input("Server: ")
        server_socket.sendto(response.encode(), client_address)

        if not data:
            # If no data received, the client has closed the connection
            print("Client disconnected.")
            break

    # Close the socket
    server_socket.close()


# Get the port number from the user
port = int(input("Enter the port number: "))
udp_server(port)
