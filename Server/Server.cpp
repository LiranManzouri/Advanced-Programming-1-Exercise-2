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
    // Saves the message.
    char message[4096] = {0};
    int i = 2;
    // Runs until it being said to stop.
    while (true) {
        // Gets the path to the unclassified flowers.
        strcpy(message, front.receiveMessage());
        // If the message is closed, it means the client closed the socket.
        if (strcmp(message, "closed") == 0) {
            // Closes the server as well, or waiting for another client.
            string option;
            cout << "Please choose an option:\n\t==> 1. Wait for another client.\n\t==> 2. Close the server."
                 << endl;
            do {
                // Gets the decision.
                cin >> option;
                // Waits for new client.
                if (option == "1") {
                    cout << "==> Waiting for client..." << endl;
                    // Closes the client socket.
                    front.closeClientSock();
                    // Gets new client.
                    front.getNewClient(i);
                    // Just added a new client.
                    i++;
                    // Closes the client socket.
                } else if (option != "2") {
                    cout << "==> Wrong key! Please choose 1 or 2 according to your wish!" << endl;
                }
                // Gets the decision until it's valid.
            } while (option != "1" && option != "2");
            // Leaves the communication.
            if (option == "2") {
                break;
                // Continue communicating.
            } else if (option == "1") {
                continue;
            }
        }
        // Classify the unclassified flowers in the given path.
        CreateClassifiedFiles createClassifiedFiles(7, message);
        pair<string *, int> flowerTypes = createClassifiedFiles.createClassified();
        char flowerTypesAsChar[4096] = {0};
        int l = 0;
        // Writes the classifiers types to the char array, seperated by '\n'.
        for (int j = 0; j < flowerTypes.second; j++) {
            for (char k: flowerTypes.first[j]) {
                flowerTypesAsChar[l] = k;
                l++;
            }
            flowerTypesAsChar[l] = '\n';
            l++;
        }
        flowerTypesAsChar[l] = '\0';
        delete[] flowerTypes.first;
        // Sends the classified to the client.
        cout << "==> Classified! Sending back to you..." << endl;
        front.sendMessage(flowerTypesAsChar);
    }
}