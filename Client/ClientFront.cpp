#include "ClientFront.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

void ClientFront::StartClient() {
    const char *ip_address = "127.0.0.1";
    const int port_no = 5555;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0){
        cout << "Error creating socket in CLIENT" << endl;
        exit(1);
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error connecting to server in CLIENT" << endl;
        exit(1);
    }
}

void ClientFront::sendMessege(char (&message)[4096]){
    unsigned long data_len = strlen(message);
    long sent_bytes = send(sock, message, data_len, 0);
    if (sent_bytes < 0)
    {
        cout << "Error sending to server in CLIENT" << endl;
        exit(1);
    }
}

char* ClientFront::reciveMessege(){
    long read_bytes = recv(sock, buffer, data_len, 0);
    if (read_bytes == 0) {
        cout << "Closed connection in CLIENT" << endl;
    } else if (read_bytes < 0) {
        cout << "Error reading in CLIENT" << endl;
        exit(1);
    }
    return buffer;
}

ClientFront::~ClientFront(){
    close(sock);
    cout << "closed socket in CLIENT" << endl;
}

//     char buffer[4096] = "Im a message";
//     unsigned long data_len = strlen(buffer);
//     int num = 1;
//     while (num != 6) {
//         num++;

//         cout << "Enter message from client to server: " << endl;
//         cin >> buffer;
//         data_len = strlen(buffer);
//         long sent_bytes = send(sock, buffer, data_len, 0);
//         if (sent_bytes < 0)
//         {
//             cout << "Error sending to server in CLIENT" << endl;
//             exit(1);
//         }

//         data_len = 4096;
//         long read_bytes = recv(sock, buffer, data_len, 0);
//         if (read_bytes == 0) {
//             cout << "Closed connection in CLIENT" << endl;
//         } else if (read_bytes < 0) {
//             cout << "Error reading in Client" << endl;
//             exit(1);
//         } else {
//             cout << buffer << endl;
//         }
//     }
// }