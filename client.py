import socket
import threading

# Create a socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 12345)
client_socket.connect(server_address)

# send function
def send_message():
    while True:
        message = input()
        client_socket.send(message.encode('utf-8'))

# receive function
def receive_message():
    while True:
        try:
            data = client_socket.recv(1024).decode('utf-8')
            print('\n' + data)
        except Exception as e:
            print(f'Error: {e}')
            break


send_thread = threading.Thread(target=send_message)
receive_thread = threading.Thread(target=receive_message)

# Start the threads
send_thread.start()
receive_thread.start()
