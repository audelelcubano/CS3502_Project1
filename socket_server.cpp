#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include <vector>

#define PORT 8080

std::vector<std::thread> client_threads; // Store client threads

void handle_client(int client_socket) {
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    std::cout << "Received: " << buffer << std::endl;

    std::string response = "Hello from Multi-Threaded Server!";
    send(client_socket, response.c_str(), response.length(), 0);
    
    close(client_socket); // Close the client socket after communication ends
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation failed\n";
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed\n";
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) { // Allow up to 10 clients
        std::cerr << "Listen failed\n";
        return -1;
    }

    std::cout << "Multi-Threaded Server listening on port " << PORT << "...\n";

    while (true) {
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_socket < 0) {
            std::cerr << "Accept failed\n";
            continue;
        }

        // Create a new thread for each client
        client_threads.emplace_back(handle_client, client_socket);
        client_threads.back().detach(); // Detach the thread so it runs independently
    }

    // Close the server socket (this part will never be reached because of while(true))
    close(server_fd);
    return 0;
}
