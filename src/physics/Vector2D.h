#ifndef DINOCAUST_VECTOR_H
#define DINOCAUST_VECTOR_H


#include <iostream>

class Vector2D {
public:
    float X, Y;

public:
    Vector2D(float x = 0, float y = 0): X(x), Y(y){
    }
public:
    inline Vector2D operator+(const Vector2D& newVector) const {
        return {X + newVector.X, Y + newVector.Y};
    }

    inline Vector2D operator-(const Vector2D& newVector) const {
        return {X - newVector.X, Y - newVector.Y};
    }

    inline Vector2D operator*(const float scalar) const {
        return Vector2D(X * scalar, Y * scalar);
    }

    void Log(std::string msg = "") {
        std::cout << msg << "(X Y) = (" << X << " " << Y << ")" << std::endl;
    }
};

#endif //DINOCAUST_VECTOR_H