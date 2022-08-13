#include "Client.h"
#include "ClientFront.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    ClientFront front;
    char message[4096] = "";
    while (strcmp(message, "close") != 0) {
        cout << "Enter the unclassified path and the desired output path:" << endl;
        cin.getline(message, 4096);
        if (strcmp(message, "close") == 0) {
            break;
        }
        char unclassifiedPath[4096];
        char outputClassifiedPath[4096];
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

        front.sendMessage(unclassifiedPath);

        char *messageReceived;
        messageReceived = front.receiveMessage();

        ofstream outputClassified;
        outputClassified.open(outputClassifiedPath);
        if (!outputClassified) {
            cerr << "Error: file couldn't be opened!" << endl;
            exit(1);
        }

        outputClassified << messageReceived << endl;

        cout << "Output file created successfully!\n" << endl;

    }
}
