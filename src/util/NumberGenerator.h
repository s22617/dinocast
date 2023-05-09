#ifndef DINOCAUST_NUMBERGENERATOR_H
#define DINOCAUST_NUMBERGENERATOR_H

#include <random>

class NumberGenerator {
public:
    static NumberGenerator* getInstance() {return sInstance = (sInstance != nullptr) ? sInstance : new NumberGenerator;
    }
    int getRandPosX();
    int getRandPosY();

private:
    NumberGenerator() {
    }
    static NumberGenerator* sInstance;
};


#endif //DINOCAUST_NUMBERGENERATOR_H
