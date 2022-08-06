//
// Created by liran on 06/08/2022.
//

#include "Server.h"
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>

#define PORT 5933

using namespace std;

int main(int argc, char const *argv[]) {

    cout << PORT << endl;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Failed creating a socket - SERVER" << endl;
        exit(1);
    }

    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Failed binding" << endl;
        exit(1);
    }

    cout << "Binding Succeed" << endl;

    if (listen(sock, 5) < 0) {
        cout << "Failed listening" << endl;
        exit(1);
    }

    cout << "Listening Succeed" << endl;

    struct sockaddr_in client_sin{};
    cout << "success - 1" << endl;
    unsigned int addr_len = sizeof(client_sin);
    cout << "success - 2" << endl;
    int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
    cout << "success - 3" << endl;
    if (client_sock < 0) {
        cout << "Failed getting the client socket!" << endl;
        exit(1);
    }

    cout << "Success! Got the client socket!" << endl;

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    long read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        cout << "connection is closed" << endl;
        return 1;
    } else if (read_bytes < 0) {
        cout << "Failed reading the info - SERVER" << endl;
        exit(1);
    }

    cout << "SERVER - Data received: " << buffer << endl;

    char data_addr[] = "K-N-N Algo";
    int data_len = 10;

    long send_bytes = send(sock, data_addr, data_len, 0);

    if (send_bytes < 0) {
        cout << "Failed sending the info! SERVER" << endl;
        exit(1);
    }

    cout << "Sent successfully!" << endl;

    close(sock);

}