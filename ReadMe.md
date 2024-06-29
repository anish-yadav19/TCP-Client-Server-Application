# TCP Client-Server Application
    This project demonstrates a basic implementation of a TCP client-server architecture in C programming language. It includes simple client and server programs that communicate over TCP/IP sockets.

# Table of Contents
        Overview
        Features
        Prerequisites
        Installation
        Usage
        
# Overview
    This project consists of two main components:

    Server: A server program (server.c) that listens for incoming connections from clients and handles client requests.
    Client: A client program (client.c) that connects to the server and sends messages or data.

# Features
    Client-Server Communication: Allows bidirectional communication between multiple clients and a server using TCP sockets.
    Simple Messaging: Demonstrates sending and receiving simple messages or data between the client and server.
    Error Handling: Includes basic error handling for socket operations and connection management.

# Prerequisites
    C Compiler: Ensure you have a C compiler installed on your system (e.g., GCC for Linux or MinGW for Windows).
    Operating System: This project should work on any operating system that supports TCP/IP sockets, including Linux, macOS, and Windows.

# Installation
    Clone the Repository:
        git clone https://github.com/your-username/tcp-client-server.git
        cd tcp-client-server
    Compile the Programs
        gcc -o server server.c
        gcc -o client client.c
    Run the Server: Start the server program first. It will listen for incoming connections on a specified port.
        ./server
    Run the Client: Start the client program, which will connect to the server's IP address and port.
        ./client




        