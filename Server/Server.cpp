#include "Server.h"
#include "ServerFront.h"
#include <iostream>
#include <cstring>
#include "../CreateClassifiedFiles.h"


using namespace std;

int main(int argc, char const *argv[])
{
    ServerFront front;
    char message[4096] = "";
    while (strcmp(message,"close") != 0){
        strcpy(message, front.receiveMessage());
        cout << "Client : " << message << endl;
    }
    cin.getline(message, 4096);
    front.sendMessage(message);
}