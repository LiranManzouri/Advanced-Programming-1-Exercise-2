//
// Created by liran on 30/07/2022.
//

#include "CreateClassifiedFiles.h"
#include "ReadFlowers.h"
#include "ClassifyFlower.h"

using namespace std;

/**
 * It reads the classified and unclassified flowers, and then
 * classifies the unclassified flowers by the three methods, and writes the results to the files
 */
pair<string *, int> CreateClassifiedFiles::createClassified() const {
    //reads the flowers
    ReadFlowers classifiedReader = ReadFlowers("classified.csv");
    ReadFlowers unclassifiedReader = ReadFlowers(unclassifiedPath);
    classifiedReader.readAndSaveFlowers();
    unclassifiedReader.readAndSaveFlowers();

    int numOfClassifiedFlowers = classifiedReader.getNumOfFlowers();
    int numOfUnclassifiedFlowers = unclassifiedReader.getNumOfFlowers();

    string flowerTypesByOrder[numOfUnclassifiedFlowers];

    Flower *classifiedFlowers = classifiedReader.getFlowers();
    Flower *unclassifiedFlowers = unclassifiedReader.getFlowers();

    //writes the classified info to the array.
    for (int i = 0; i < numOfUnclassifiedFlowers; i++) {
        const Flower unclassifiedFlower = unclassifiedFlowers[i];
        ClassifyFlower classifyFlower(unclassifiedFlower, classifiedFlowers, numOfClassifiedFlowers, k);
        flowerTypesByOrder[i] = classifyFlower.euclideanClassify();
    }

    pair<string *, int> typesAndNumOfTypesPair(flowerTypesByOrder, numOfUnclassifiedFlowers);

    return typesAndNumOfTypesPair;
}
