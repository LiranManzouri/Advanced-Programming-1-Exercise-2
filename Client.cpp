//
// Created by liran on 06/08/2022.
//

#include "Client.h"
// #include "ReadFlowers.h"

#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <iostream>

#define PORT 5933

using namespace std;

int main(int argc, char const *argv[]) {

    cout << PORT << endl;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Failed creating a socket!" << endl;
        exit(1);
    }

    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;

    sin.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Failed connecting!" << endl;
        exit(1);
    }

    char messages[] = "The Fu MSG";
//  string messages[] = {argv[0], argv[1]};
    unsigned long messages_len = /*arr[0].length() + arr[1].length()*//*2*/10;
    long sent_bytes = send(sock, /*message*/messages, messages_len, 0);

    if (sent_bytes < 0) {
        cout << "Failed sending the info!" << endl;
        exit(1);
    }

    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer) / sizeof(char);

    long read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        cout << "connection is closed" << endl;
        return 1;
    }

    if (read_bytes < 0) {
        cout << "Failed receiving the info!" << endl;
        exit(1);
    }

    cout << "Data received: " << buffer << endl;

    close(sock);
}