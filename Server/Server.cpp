#include "ServerFront.h"
#include <iostream>
#include <cstring>
#include "../CreateClassifiedFiles.h"


using namespace std;

/*
 * Main for the server, to communicate with the clients.
 * The server gets a path to unclassified flowers from a client and
 * classify them, after that, the server sends it back to the client.
 */
int main(int argc, char const *argv[]) {
    // Responsible for the communication.
    ServerFront front;
    char message[4096] = {0};
    while (true) {
        strcpy(message, front.receiveMessage());
        if (strcmp(message, "close") == 0) {
            break;
        }

        CreateClassifiedFiles createClassifiedFiles(7, message);

        pair<string *, int> flowerTypes = createClassifiedFiles.createClassified();
        char flowerTypesAsChar[4096];
        int l = 0;
        for (int j = 0; j < flowerTypes.second; j++) {
            for (char k: flowerTypes.first[j]) {
                flowerTypesAsChar[l] = k;
                l++;
            }
            flowerTypesAsChar[l] = '\n';
            l++;
        }
        cout << "Classified! Sending back to you...\n" << endl;
        front.sendMessage(flowerTypesAsChar);
    }
}