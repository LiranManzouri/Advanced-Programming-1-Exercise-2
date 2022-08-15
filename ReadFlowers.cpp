//
// Created by liran on 28/07/2022.
//

#include "ReadFlowers.h"
#include <iostream>
#include <fstream>

using namespace std;

void ReadFlowers::readAndSaveFlowers() {
    int numOfFlowers = getNumOfFlowers();
    flowers = new Flower[numOfFlowers];
    ifstream flowersInputFile;
    flowersInputFile.open(fileName);
    if (!flowersInputFile) {
        cerr << "Error: file couldn't be opened" << endl;
        exit(1);
    }
    string line;
    const char delim = ',';
    int index = 0;
    int i = 0;
    while (!flowersInputFile.eof()) {
        getline(flowersInputFile, line);
        if (line.empty()) {
            continue;
        }
        string token1 = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + 1);
        string token2 = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + 1);
        string token3 = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + 1);
        string token4 = line.substr(0, line.find(delim));
        string flowerType;
        if (line.find(delim) != string::npos) {
            line.erase(0, line.find(delim) + 1);
            flowerType = line;
            line.erase();
        }
        double calyxLeavesLength = stod(token1);
        double calyxLeavesWidth = stod(token2);
        double petalLength = stod(token3);
        double petalWidth = stod(token4);
        Flower flower = Flower(flowerType, calyxLeavesLength, calyxLeavesWidth, petalLength, petalWidth);
        flowers[index] = flower;
        index++;
    }
}

int ReadFlowers::getNumOfFlowers() {
    int numOfFlowers = 0;
    ifstream inputFile;
    inputFile.open(fileName);
    string line;
    while (!inputFile.eof()) {
        getline(inputFile, line);
        if (line.empty()) {
            cout << "111" << endl;
            continue;
        }
        numOfFlowers++;
    }
    return numOfFlowers;
}