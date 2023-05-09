#include <iostream>
#include "NumberGenerator.h"

NumberGenerator* NumberGenerator::sInstance = nullptr;
std::random_device generator;
std::mt19937 mt(generator());

std::uniform_int_distribution<std::mt19937::result_type> distributionPosX(0,884);
std::uniform_int_distribution<std::mt19937::result_type> distributionPosY(0, 50);

int NumberGenerator::getRandPosX() {

    return (int) distributionPosX(mt);
}

int NumberGenerator::getRandPosY() {

    return (int) distributionPosY(mt);
}