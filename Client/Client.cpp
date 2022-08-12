#include "Client.h"
#include "ClientFront.h"

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {

/*
    string unclassifiedPath = argv[0];
    string classifiedPath = argv[1];
*/

//    string paths[] = {unclassifiedPath, classifiedPath};
    ClientFront front;
    char message[4096] = "";
    while (strcmp(message, "close") != 0) {
        cin.getline(message, 4096);
        front.sendMessage(message);
    }
}
