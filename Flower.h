//
// Created by liran on 19/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_FLOWER_H
#define ADVANCED_PROGRAMMING_1_FLOWER_H


#include <string>

class Flower {
    std::string m_flowerType;
    double m_calyxLeavesLength;
    double m_calyxLeavesWidth;
    double m_petalLength;
    double m_petalWidth;
public:
    
    // constructor for the flower class
    Flower(std::string flowerType, double calyxLeavesLength, double calyxLeavesWidth, double petalLength,
           double petalWidth) : m_calyxLeavesLength(calyxLeavesLength), m_calyxLeavesWidth(calyxLeavesWidth),
                                m_petalLength(petalLength), m_petalWidth(petalWidth), m_flowerType(move(flowerType)) {}

    Flower() : m_calyxLeavesLength(0), m_calyxLeavesWidth(0),
               m_petalLength(0), m_petalWidth(0) {}

    Flower(const Flower &flower) = default;

    ~Flower() = default;

    //getters
    std::string getFlowerType() const;

    double getCalyxLeavesLength() const;

    double getCalyxLeavesWidth() const;

    double getPetalLength() const;

    double getPetalWidth() const;

    Flower &operator=(const Flower &flower) {
        if (this == &flower) {
            return *this;
        }
        m_flowerType = flower.m_flowerType;
        m_calyxLeavesLength = flower.m_calyxLeavesLength;
        m_calyxLeavesWidth = flower.m_calyxLeavesWidth;
        m_petalLength = flower.m_petalLength;
        m_petalWidth = flower.m_petalWidth;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Flower &flower);

#endif //ADVANCED_PROGRAMMING_1_FLOWER_H
