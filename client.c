// Client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8080
#define BUFFER_SIZE 1024

#pragma comment(lib, "ws2_32.lib") // Link with Winsock library

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converting IPv4 and IPv6 addresses from text to binary form
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    char *message = "Hello from client";
    send(sock, message, strlen(message), 0);
    printf("Message sent\n");

    int valread = recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Echo from server: %s\n", buffer);

    // Closing the socket
    closesocket(sock);
    WSACleanup();


    return 0;
}
