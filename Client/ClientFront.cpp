#include "ClientFront.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

void ClientFront::StartClient() {
    cout << "CLIENT" << endl;
    const int port_no = 5555;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket in CLIENT" << endl;
        exit(1);
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error connecting to server in CLIENT" << endl;
        exit(1);
    }
}

void ClientFront::sendMessage(char (&message)[4096]) const {
    unsigned long my_data_len = strlen(message);
    long sent_bytes = send(sock, message, my_data_len, 0);
    if (sent_bytes < 0) {
        cout << "Error sending to server in CLIENT" << endl;
        exit(1);
    }
}


char *ClientFront::receiveMessage() {
    for (int i = 0; i < data_len; i++) {
        buffer[i] = '\0';
    }

    long read_bytes = recv(sock, buffer, data_len, 0);
    if (read_bytes == 0) {
        cout << "Closed connection in CLIENT" << endl;
    } else if (read_bytes < 0) {
        cout << "Error reading in CLIENT" << endl;
        exit(1);
    }

    return buffer;
}

ClientFront::~ClientFront() {
    close(sock);
    cout << "closed socket in CLIENT" << endl;
}
