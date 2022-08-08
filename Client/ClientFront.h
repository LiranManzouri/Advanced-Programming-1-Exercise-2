#include <string>
#include <utility>

class ClientFront {

private:
    int sock;
    const int data_len = 4096;
    char buffer[4096];

    void StartClient() const;

public:

    ClientFront() {
        StartClient();
    }

    void sendMessege(const char message[4096]) const;
    const char* reciveMessege() const;
    ~ClientFront();
};