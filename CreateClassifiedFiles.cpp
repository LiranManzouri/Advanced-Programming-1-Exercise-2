//
// Created by liran on 30/07/2022.
//

#include "CreateClassifiedFiles.h"
#include "ReadFlowers.h"
#include "ClassifyFlower.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * It reads the classified and unclassified flowers, and then
 * classifies the unclassified flowers by the three methods, and writes the results to the files
 */
void CreateClassifiedFiles::createClassified() const {

    //opens all the files, and makes sure there are no errors
    ofstream classifyByEuclideanFile;
    classifyByEuclideanFile.open("euclidean_output.csv");
    if (!classifyByEuclideanFile) {
        cerr << "Error: file couldn't be opened" << endl;
        exit(1);
    }

    ofstream classifyByChebyshevFile;
    classifyByChebyshevFile.open("chebyshev_output.csv");
    if (!classifyByChebyshevFile) {
        cerr << "Error: file couldn't be opened" << endl;
        exit(1);
    }

    ofstream classifyByManhattanFile;
    classifyByManhattanFile.open("manhattan_output.csv");
    if (!classifyByManhattanFile) {
        cerr << "Error: file couldn't be opened" << endl;
        exit(1);
    }

    //reads the flowers
    ReadFlowers classifiedReader = ReadFlowers("classified.csv");
    ReadFlowers unclassifiedReader = ReadFlowers("Unclassified.csv");

    classifiedReader.readAndSaveFlowers();
    unclassifiedReader.readAndSaveFlowers();

    Flower *classifiedFlowers = classifiedReader.getFlowers();
    int numOfClassifiedFlowers = classifiedReader.getNumOfFlowers();

    //writes the classified info to the files
    for (int i = 0; i < unclassifiedReader.getNumOfFlowers(); i++) {
        const Flower unclassifiedFlower = unclassifiedReader.getFlowers()[i];
        ClassifyFlower classifyFlower = ClassifyFlower(unclassifiedFlower, classifiedFlowers,
                                                       numOfClassifiedFlowers, k);
        string flowerTypeByEuclidean = classifyFlower.euclideanClassify();
        classifyByEuclideanFile << flowerTypeByEuclidean << endl;

        string flowerTypeByChebyshev = classifyFlower.chebyshevClassify();
        classifyByChebyshevFile << flowerTypeByChebyshev << endl;

        string flowerTypeByManhattan = classifyFlower.manhattanClassify();
        classifyByManhattanFile << flowerTypeByManhattan << endl;
    }

    classifyByEuclideanFile.close();
    classifyByChebyshevFile.close();
    classifyByManhattanFile.close();

}