#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error: Could not create socket." << std::endl;
        return 1;
    }

    // Connect to the server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error: Could not connect to the server." << std::endl;
        return 1;
    }

    std::cout << "Connected to the server." << std::endl;

    // Communication loop
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));

        // Send a message to the server
        std::cout << "You: ";
        std::string message;
        std::getline(std::cin, message);
        send(clientSocket, message.c_str(), message.size(), 0);

        // Receive a response from the server
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Server disconnected." << std::endl;
            break;
        }

        std::cout << "Server: " << buffer << std::endl;
    }

    // Close the socket
    close(clientSocket);

    return 0;
}
