//
// Created by liran on 29/07/2022.
//

#include "ClassifyFlower.h"
#include "DistanceCalculator.h"
#include "KNN.h"

using namespace std;

pair<Flower *, double> *ClassifyFlower::getEuclideanDistances() const {
    auto *euclideanDistances = new pair<Flower *, double>[numOfFlowers];
    for (int i = 0; i < numOfFlowers; i++) {
        euclideanDistances[i] = (pair<Flower *, double>(&flowers[i],
                                                        DistanceCalculator::euclidean(unclassifiedFlower, flowers[i])));
    }
    return euclideanDistances;
}

string ClassifyFlower::euclideanClassify() {
    pair<Flower *, double> *euclideanDistances = getEuclideanDistances();
    KNN::QuickSelect(k, euclideanDistances, 0, numOfFlowers - 1);
    return classifyByKNN(euclideanDistances);

}

// runs the KNN algo on the array of pairs, then looks at the k first
// elements and classfy the flower by them
string ClassifyFlower::classifyByKNN(pair<Flower *, double> *distances) const {
    int counterForIrisSetosa = 0;
    int counterForIrisVersicolor = 0;
    int counterForIrisVirginica = 0;
    
    for (int i = 0; i < k; i++) {
        if (distances[i].first->getFlowerType() == "Iris-setosa") {
            counterForIrisSetosa++;
        }
        if (distances[i].first->getFlowerType() == "Iris-versicolor") {
            counterForIrisVersicolor++;
        }
        if (distances[i].first->getFlowerType() == "Iris-virginica") {
            counterForIrisVirginica++;
        }
    }

    delete[] distances;

    int maxCounter = counterForIrisSetosa;
    maxCounter = max(maxCounter, counterForIrisVersicolor);
    maxCounter = max(maxCounter, counterForIrisVirginica);

    if (maxCounter == counterForIrisSetosa) {
        return "Iris-setosa";
    }
    if (maxCounter == counterForIrisVersicolor) {
        return "Iris-versicolor";
    }
    return "Iris-virginica";
}
