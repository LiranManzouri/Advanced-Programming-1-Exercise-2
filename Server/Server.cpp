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
    int i = 2;
    while (true) {
        strcpy(message, front.receiveMessage());
        if (strcmp(message, "closed") == 0) {
            string option;
//            bool exitServer = false;
            cout << "Please choose an option:\n\t==> 1. Wait for another client.\n\t==> 2. Close the server."
                 << endl;
            do {
                cin >> option;
                if (option == "1") {
                    front.closeClientSock();
                    front.getNewClient(i);
                    i++;
                } else if (option != "2") {
//                    exitServer = true;
                    cout << "==> Wrong key! Please choose 1 or 2 according to your wish!" << endl;
                } /*else {
                }*/
            } while (option != "1" && option != "2");
            if (option == "2") {
                break;
            } else if (option == "1") {
                continue;
            }
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
        cout << "==> Classified! Sending back to you...\n" << endl;
        front.sendMessage(flowerTypesAsChar);
    }
}