#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_2_SERVERFRONT_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_2_SERVERFRONT_H

class ServerFront {
private:
    int client_sock;
    const int data_len = 4096;
    char buffer[4096];
    int sock;

    void StartServer();

public:
    ServerFront() {
        StartServer();
    }

    ~ServerFront();

//    void sendMessage(char (&message)[4096]);
    char *receiveMessage();
};

#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_SERVERFRONT_H
