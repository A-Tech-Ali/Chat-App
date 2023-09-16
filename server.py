import socket
import threading

# Create a socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 12345)

server_socket.bind(server_address)

# Listen for incoming connections (max 5 clients in the queue)
server_socket.listen(5)

print('Server is listening for incoming connections...')

clients = []

def handle_client(client_socket):
    while True:
        try:
            # Receive data from the client
            data = client_socket.recv(1024).decode('utf-8')
            if not data:
                break  # If no data received, exit the loop
            print('Received:', data)

            for client in clients:
                client.send(data.encode('utf-8'))
        except Exception as e:
            print(f'Error: {e}')
            break

    clients.remove(client_socket)
    client_socket.close()

# Accept and handle incoming connections
while True:
    client_socket, client_address = server_socket.accept()
    print(f'Accepted connection from {client_address}')
    clients.append(client_socket)

    client_thread = threading.Thread(target=handle_client, args=(client_socket,))
    client_thread.start()
