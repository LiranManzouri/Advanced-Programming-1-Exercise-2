#include <string>
#include <utility>


/**
 * Class that is in control of communicating between the client
 * and the server, and represents the client in this communication.
 */
class ClientFront {

private:
    // Socket, data length for the messages and buffer to save the received message.
    int sock = 0;
    const int data_len = 4096;
    char buffer[4096] = {0};

    // Creates the socket and connecting the client to the server.
    void StartClient();

public:

    // Constructor.
    ClientFront() {
        StartClient();
    }

    // Sends message to the server.
    void sendMessage(char (&message)[4096]) const;

    // Receives message from the server.
    char *receiveMessage();

    // Destructor.
    ~ClientFront();
};