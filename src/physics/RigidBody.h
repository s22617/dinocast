#ifndef DINOCAUST_RIGIDBODY_H
#define DINOCAUST_RIGIDBODY_H

#include "Vector2D.h"
#include <cmath>

const float DEFAULT_MASS_VALUE = 1.0f;
const float GRAVITY_FORCE = 9.8f;

class RigidBody {
public:
    RigidBody() {
        mMass = DEFAULT_MASS_VALUE;
        mGravity = GRAVITY_FORCE;
    }

    inline void setMass(float mass) {
        mMass = mass;
    }

    inline void setGravity(float gravity) {
        mGravity = gravity;
    }

    inline void applyForceX(float forceX) {
        mForce.X = forceX;
    }

    inline void applyForceY(float forceY) {
        mForce.Y = forceY;
    }

    // null vector for disabling force when not needed
    inline void unsetForce() {
        mForce = Vector2D(0, 0);
    }

    inline float getMass() {
        return mMass;
    }

    inline Vector2D getPosition() {
        return mPosition;
    }

    inline Vector2D getVelocity() {
        return mVelocity;
    }

    inline Vector2D getAcceleration() {
        return mAcceleration;
    }

    float updateEnemyFalling(float dt) {

        mAcceleration.Y = (mAcceleration.Y + mGravity / mMass);

        mVelocity.Y = mAcceleration.Y * dt;

        float addPositionY = mVelocity.Y * dt / 1000.0f;
        //std::cout << addPositionY << std::endl;
        if (addPositionY > 5) {
            addPositionY = 5;
        }

        return addPositionY;
    }

    void updatePlayerMoving(float dt) {
        mAcceleration.X = mForce.X/mMass;

        mVelocity = mAcceleration * dt;

        mPosition = mVelocity * dt;
    }

private:
    float mMass;
    float mGravity;

    Vector2D mForce;
    Vector2D mPosition;
    Vector2D mVelocity;
    Vector2D mAcceleration;
};

#endif //DINOCAUST_RIGIDBODY_H
