#include "ClientFront.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/*
 * Main for the client, to communicate with the server.
 * The client sends a path to unclassified flowers to the server and get their classify,
 * after that, the client writes the classifiers to the output file.
 */
int main(int argc, char const *argv[]) {
    // Responsible for the communication.
    ClientFront front;
    // Saves the message.
    char message[4096] = {0};
    // Stops the communication after getting the close message.
    while (strcmp(message, "close") != 0) {
        // Asks for the paths.
        cout << "==> Enter the unclassified path and the desired output path:" << endl;
        cout << "    NOTE: for closing the client socket and stop the communication" << endl
             << "    send here \"close\"." << endl;
        cin.getline(message, 4096);
        // Stops after "close".
        if (strcmp(message, "close") == 0) {
            break;
        }
        // Saves the paths.
        char unclassifiedPath[4096] = {0};
        char outputClassifiedPath[4096] = {0};
        // Gets the paths.
        int i = 0, k = 0;
        while (message[i] != ' ') {
            unclassifiedPath[k] = message[i];
            i++, k++;
        }
        unclassifiedPath[k] = '\0';
        i++;
        k = 0;
        while (message[i] != '\0') {
            outputClassifiedPath[k] = message[i];
            i++, k++;
        }
        outputClassifiedPath[k] = '\0';
        // Send the unclassified path to the server.
        front.sendMessage(unclassifiedPath);

        // Gets the types of the flowers after the server classified them.
        char messageReceived[4096] = {0};
        strcpy(messageReceived, front.receiveMessage());

        // Opens the output file.
        ofstream outputClassified;
        outputClassified.open(outputClassifiedPath);
        if (!outputClassified) {
            cerr << "Error: file couldn't be opened!" << endl;
            exit(1);
        }

        // Writes the classifiers to the output file.
        outputClassified << messageReceived << endl;

        outputClassified.close();

        // Notifies that everything went successful.
        cout << "==> Output file created successfully!\n" << endl;
    }
}