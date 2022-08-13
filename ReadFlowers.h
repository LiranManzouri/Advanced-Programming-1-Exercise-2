#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_2_READFLOWERS_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_2_READFLOWERS_H

#include "Flower.h"

class ReadFlowers {

    const std::string fileName;
    Flower *flowers;

public:

    explicit ReadFlowers(std::string fileName) : fileName(move(fileName)) {
        flowers = nullptr;
    }

    //destructor for the flowers arr
    ~ReadFlowers() {
        delete[] flowers;
    }

    Flower *getFlowers() {
        return flowers;
    }

    //gets the number of flowers in the file by going line by line
    int getNumOfFlowers();

    //reads the flowers from the files and saves them in a locel varible "flowers[]"
    void readAndSaveFlowers();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_READFLOWERS_H
