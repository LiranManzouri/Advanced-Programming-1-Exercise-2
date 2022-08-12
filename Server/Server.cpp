#include "Server.h"
#include "ServerFront.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    ServerFront front;
    char message[4096] = "";
    while (strcmp(message,"close") != 0){
        strcpy(message, front.receiveMessage());
        cout << "Client : " << message << endl;
    }
}