import socket

def udp_client(port):
    host = input("Enter the server IP address: ")

    # Create a UDP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    print(f"Connected to server: {host}:{port}")

    while True:
        # Send a message to the server
        message = input("Client: ")
        client_socket.sendto(message.encode(), (host, port))

        # Receive a response from the server
        response, server_address = client_socket.recvfrom(1024)
        print(f"Server: {response.decode()}")

        if message.lower() == "bye":
            # If the message is "bye", close the connection
            print("Closing the connection.")
            break

    # Close the socket
    client_socket.close()


# Get the port number from the user
port = int(input("Enter the port number: "))
udp_client(port)
