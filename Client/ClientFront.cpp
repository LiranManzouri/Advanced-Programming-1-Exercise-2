#include "ClientFront.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

using namespace std;

/**
 * Initializes the client and connecting it to the server.
 */
void ClientFront::StartClient() {
    cout << "CLIENT" << endl;
    // Port to use.
    const int port_no = 5555;
    // Creates the socket and checks it created successfully.
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket in CLIENT" << endl;
        exit(1);
    }
    // Initializes the info about the socket.
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port_no);
    // Connecting the socket to the server.
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error connecting to server in CLIENT" << endl;
        exit(1);
    }
}

/**
 * Sends message to the server.
 * @param message is the message that is being sent to the server.
 */
void ClientFront::sendMessage(char (&message)[4096]) const {
    // Sends and checks that it sent successfully.
    unsigned long my_data_len = strlen(message);
    long sent_bytes = send(sock, message, my_data_len, 0);
    if (sent_bytes < 0) {
        cout << "Error sending to server in CLIENT" << endl;
        exit(1);
    }
}

/**
 * Receives message from the server.
 * @return the message that received.
 */
char *ClientFront::receiveMessage() {
    // Cleans the buffer.
    for (int i = 0; i < data_len; i++) {
        buffer[i] = '\0';
    }

    // receives and checks that the connection is still fine and the info received successfully.
    long read_bytes = recv(sock, buffer, data_len, 0);
    if (read_bytes == 0) {
        cout << "Closed connection in CLIENT" << endl;
    } else if (read_bytes < 0) {
        cout << "Error reading in CLIENT" << endl;
        exit(1);
    }

    // Returns the received message.
    return buffer;
}

/**
 * Destructor.
 */
ClientFront::~ClientFront() {
    // Closes the socket.
    close(sock);
    cout << "closed socket in CLIENT" << endl;
}
