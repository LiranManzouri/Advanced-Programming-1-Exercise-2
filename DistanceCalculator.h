#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_2_DISTANCECALCULATOR_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_2_DISTANCECALCULATOR_H

#include "Flower.h"

class DistanceCalculator {

public:
    //implements all 3 distances asked
    static double euclidean(const Flower& f1, const Flower& f2);

    static double chebyshev(const Flower& f1, const Flower& f2);

    static double manhattan(const Flower& f1, const Flower& f2);

};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_DISTANCECALCULATOR_H
