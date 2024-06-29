// Server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8080
#define BUFFER_SIZE 1024

#pragma comment(lib, "ws2_32.lib") // Link with Winsock library

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the network address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        printf("Listen failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    printf("Server is listening on port %d\n", PORT);

    // Accepting an incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) == INVALID_SOCKET) {
        printf("Accept failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Reading the message from the client
    int valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
    printf("Received: %s\n", buffer);

    // Echoing the message back to the client
    send(new_socket, buffer, strlen(buffer), 0);
    printf("Echo message sent\n");

    // Closing the socket
    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}
