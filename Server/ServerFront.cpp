#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include "ServerFront.h"

using namespace std;

/**
 * Initializes the server and connecting it to the first client.
 */
void ServerFront::StartServer() {
    // Prints "SERVER" with bold and underline, in the middle of the terminal.
    for (int i = 0; i < 37; i++) {
        cout << " ";
    }
    cout << "\033[4m\e[1mSERVER\e[0m\033[0m" << endl;
    // Port to use.
    const int server_port = 5555;
    // Creates the socket and checks it created successfully.
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket in SERVER" << endl;
        exit(1);
    }
    // Initializes the info about the socket.
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    // Binding the socket and checks it bind successfully.
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error binding socket in SERVER" << endl;
        exit(1);
    }
    // Gets the first client.
    getNewClient(1);
}

/**
 * Receives a message from the client.
 * @return the received message.
 */
char *ServerFront::receiveMessage() {
    // Cleans the buffer.
    for (int i = 0; i < data_len; i++) {
        buffer[i] = '\0';
    }

    // receives and checks that the connection is still fine and the info received successfully.
    long read_bytes = recv(client_sock, buffer, data_len, 0);
    if (read_bytes == 0) {
        strcpy(buffer, "closed");
        cout << "==> Closed connection with the client! ";
    } else if (read_bytes < 0) {
        cout << "Error reading in SERVER" << endl;
        exit(1);
    }
    // Returns the received message.
    return buffer;
}

/**
 * Sends a message to a client.
 * @param message is the message we sent.
 */
void ServerFront::sendMessage(char (&message)[4096]) const {
    // Sends and checks that it sent successfully.
    long sent_bytes = send(client_sock, message, data_len, 0);
    if (sent_bytes < 0) {
        cout << "Error sending to client in SERVER" << endl;
        exit(1);
    }
}

/**
 * Destructor.
 */
ServerFront::~ServerFront() {
    cout << "Closing socket in SERVER" << endl;
    close(sock);
}

/**
 * Gets new client to the server.
 * @param i is the client's number.
 */
void ServerFront::getNewClient(int i) {
    // Waits for a client.
    if (listen(sock, 1) < 0) {
        cout << "Error listening to a socket in SERVER" << endl;
        exit(1);
    }
    // Accepts the client and checks it went successfully.
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        cout << "Error accepting client in SERVER" << endl;
        exit(1);
    }
    // Prints the client's number.
    if (i == 1) {
        cout << "The 1st Client accepted!" << endl;
    } else if (i == 2) {
        cout << "\nThe 2nd Client accepted!" << endl;
    } else if (i == 3) {
        cout << "\nThe 3rd Client accepted!" << endl;
    } else {
        cout << "\nThe " << i << "th Client accepted!" << endl;
    }
}

/**
 * Closes the current client socket.
 */
void ServerFront::closeClientSock() const {
    close(client_sock);
}