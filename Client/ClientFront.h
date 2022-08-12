#include <string>
#include <utility>

class ClientFront {

private:
    int sock;
    const int data_len = 4096;
    char buffer[4096];

    void StartClient();

public:

    ClientFront() {
        StartClient();
    }

    void sendMessage(char (&message)[4096]) const;
//    char* receiveMessege();
    ~ClientFront();
};