//
// Created by liran on 30/07/2022.
//

#include "CreateClassifiedFiles.h"
#include "ReadFlowers.h"
#include "ClassifyFlower.h"
#include "iostream"

using namespace std;

/**
 * It reads the classified and unclassified flowers, and then
 * classifies the unclassified flowers by the three methods, and writes the results to the files
 */
pair<string*, int> CreateClassifiedFiles::createClassified() const {
    //reads the flowers
    ReadFlowers classifiedReader = ReadFlowers("classified.csv");
    ReadFlowers unclassifiedReader = ReadFlowers(unclassifiedPath);
    classifiedReader.readAndSaveFlowers();
    unclassifiedReader.readAndSaveFlowers();
    Flower *classifiedFlowers = classifiedReader.getFlowers();
    int numOfClassifiedFlowers = classifiedReader.getNumOfFlowers();
    string flowerTypesByOrder[unclassifiedReader.getNumOfFlowers()];

    //writes the classified info to the files
    for (int i = 0; i < unclassifiedReader.getNumOfFlowers(); i++) {
        const Flower unclassifiedFlower = unclassifiedReader.getFlowers()[i];
        ClassifyFlower classifyFlower = ClassifyFlower(unclassifiedFlower, classifiedFlowers,
                                                       numOfClassifiedFlowers, k);
        string flowerTypeByEuclidean = classifyFlower.euclideanClassify();
        flowerTypesByOrder[i] = flowerTypeByEuclidean;
    }

    pair<string*, int> pair(flowerTypesByOrder, unclassifiedReader.getNumOfFlowers());

    return pair;
}
