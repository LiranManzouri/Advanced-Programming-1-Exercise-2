#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include "ServerFront.h"

using namespace std;

void ServerFront::StartServer() {
    for (int i = 0; i < 37; i++) {
        cout << " ";
    }
    cout << "\033[4m\e[1mSERVER\e[0m\033[0m" << endl;
    const int server_port = 5555;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket in SERVER" << endl;
        exit(1);
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error binding socket in SERVER" << endl;
        exit(1);
    }
    getNewClient(1);

//    struct sockaddr_in client_sin{};
//    unsigned int addr_len = sizeof(client_sin);
//    client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
//    if (client_sock < 0) {
//        cout << "Error accepting client in SERVER" << endl;
//        exit(1);
//    }
}

char *ServerFront::receiveMessage() {
    for (int i = 0; i < data_len; i++) {
        buffer[i] = '\0';
    }

    long read_bytes = recv(client_sock, buffer, data_len, 0);

    if (read_bytes == 0) {
        strcpy(buffer, "closed");
        cout << "==> Closed connection with the client! ";
//        exit(1);
    } else if (read_bytes < 0) {
        cout << "Error reading in SERVER" << endl;
        exit(1);
    }
    return buffer;
}


void ServerFront::sendMessage(char (&message)[4096]) const {
    long sent_bytes = send(client_sock, message, data_len, 0);
    if (sent_bytes < 0) {
        cout << "Error sending to client in SERVER" << endl;
        exit(1);
    }
}


ServerFront::~ServerFront() {
    cout << "\nClosing socket in SERVER" << endl;
    close(sock);
}

void ServerFront::getNewClient(int i) {
    if (listen(sock, 1) < 0) {
        cout << "Error listening to a socket in SERVER" << endl;
        exit(1);
    }
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        cout << "Error accepting client in SERVER" << endl;
        exit(1);
    }
    if (i == 1) {
        cout << "The 1st Client accepted!" << endl;
    } else if (i == 2) {
        cout << "The 2nd Client accepted!" << endl;
    } else if (i == 3) {
        cout << "The 3rd Client accepted!" << endl;
    } else {
        cout << "The " << i << "th Client accepted!" << endl;
    }
}


void ServerFront::closeClientSock() {
    close(client_sock);
}
