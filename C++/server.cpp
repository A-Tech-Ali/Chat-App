#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error: Could not create socket." << std::endl;
        return 1;
    }

    // Bind the socket to an address and port
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error: Could not bind to port." << std::endl;
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error: Could not listen on port." << std::endl;
        return 1;
    }

    std::cout << "Server is listening for incoming connections..." << std::endl;

    // Accept a client connection
    sockaddr_in clientAddress;
    socklen_t clientSize = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientSize);
    if (clientSocket == -1) {
        std::cerr << "Error: Could not accept client connection." << std::endl;
        return 1;
    }

    std::cout << "Client connected." << std::endl;

    // Communication loop
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));

        // Receive data from the client
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Client disconnected." << std::endl;
            break;
        }

        std::cout << "Client: " << buffer << std::endl;

        // Send a response to the client
        std::cout << "You: ";
        std::string message;
        std::getline(std::cin, message);
        send(clientSocket, message.c_str(), message.size(), 0);
    }

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
