#include "Vector2D.h"

#ifndef DINOCAUST_TRANSFORM_H
#define DINOCAUST_TRANSFORM_H



class Transform {
public:
    float X, Y;
public:
    Transform(float x=0, float y=0): X(x), Y(y){}

public:
    inline void TranslateX(float x) {
        X+=x;
    }
    inline void TranslateY(float y) {
        Y+=y;
    }
    inline void Translate(Vector2D vector) {
        X += vector.X;
        Y += vector.Y;
    }
};

#endif //DINOCAUST_TRANSFORM_H