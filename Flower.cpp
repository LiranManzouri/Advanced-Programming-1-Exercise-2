//
// Created by liran on 19/07/2022.
//

#include "Flower.h"
#include "iostream"

using namespace std;

string Flower::getFlowerType() const {
    return m_flowerType;
}

double Flower::getPetalLength() const {
    return m_petalLength;
}

double Flower::getPetalWidth() const {
    return m_petalWidth;
}

double Flower::getCalyxLeavesLength() const {
    return m_calyxLeavesLength;
}

double Flower::getCalyxLeavesWidth() const {
    return m_calyxLeavesWidth;
}

ostream &operator<<(ostream &os, const Flower &flower) {
    if (flower.getFlowerType().empty()) {
        return os << flower.getCalyxLeavesLength() << " " << flower.getCalyxLeavesWidth()
                  << " " << flower.getPetalLength() << " " << flower.getPetalWidth();
    }
    return os << flower.getFlowerType() << " " << flower.getCalyxLeavesLength() << " "
              << flower.getCalyxLeavesWidth() << " " << flower.getPetalLength() << " " << flower.getPetalWidth();
}