//
// Created by liran on 30/07/2022.
//

#include "CreateClassifiedFiles.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "You must enter a number for calculating the K-N-N!" << endl;
        return 0;
    }
    // takes the argument for the k in the algo , and kickstarts the program
    CreateClassifiedFiles createClassifiedFiles = CreateClassifiedFiles(stoi(argv[1]));
    createClassifiedFiles.createClassified();
}