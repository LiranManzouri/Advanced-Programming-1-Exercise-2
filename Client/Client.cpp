#include "Client.h"
#include "ClientFront.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ClientFront front;
    const char message[4096] = "hello";
    front.sendMessege(message);
    cout << front.reciveMessege() << endl;
    delete &front;
}
