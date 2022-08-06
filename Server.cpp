#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
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
    if (listen(sock, 5) < 0) {
        cout << "Error listening to a socket in SERVER" << endl;
        exit(1);
    }
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        cout << "Error accepting client in SERVER" << endl;
        exit(1);
    }
    int num = 1;
    while (num != 6) {
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        num++;
        long read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            cout << "Closed connection in SERVER" << endl;
        } else if (read_bytes < 0) {
            cout << "Error reading in SERVER" << endl;
            exit(1);
        } else {
            cout << buffer << endl;
        }
        cout << "Enter message from server to client: " << endl;
        cin >> buffer;
        long sent_bytes = send(client_sock, buffer, read_bytes, 0);
        if (sent_bytes < 0) {
            cout << "Error sending to client in SERVER" << endl;
            exit(1);
        }
    }
    cout << "Closing socket in SERVER" << endl;
    close(sock);
    return 0;
}