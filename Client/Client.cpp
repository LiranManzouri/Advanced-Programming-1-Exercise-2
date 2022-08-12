#include "Client.h"
#include "ClientFront.h"

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
    ClientFront front;
    char message[4096] = "";
    while (strcmp(message, "close") != 0) {
        cin.getline(message, 4096);
        front.sendMessege(message);
    }
}
