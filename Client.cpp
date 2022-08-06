#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    const char *ip_address = "127.0.0.1";
    const int port_no = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
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
    char data_addr[] = "Im a message";
    unsigned long data_len = strlen(data_addr);
    int num = 1;
    while (num != 6) {
        num++;
        cout << "Enter message from client to server: " << endl;
        cin >> data_addr;
        long sent_bytes = send(sock, data_addr, data_len, 0);
        if (sent_bytes < 0) {
            cout << "Error sending to server in CLIENT" << endl;
            exit(1);
        }
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        long read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            cout << "Closed connection in CLIENT" << endl;
        } else if (read_bytes < 0) {
            cout << "Error reading in Client" << endl;
            exit(1);
        } else {
            cout << buffer << endl;
        }
    }
    close(sock);
    return 0;
}