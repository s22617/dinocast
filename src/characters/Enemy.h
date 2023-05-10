#ifndef DINOCAUST_ENEMY_H
#define DINOCAUST_ENEMY_H

#include "Character.h"
#include "../physics/RigidBody.h"
#include "../collision/Collider.h"
#include "../animation/Animation.h"

class Enemy : public Character {
public:
    Enemy(Properties* p, int health);

    virtual void draw();
    virtual void clean();
    virtual void update(float dt);

    Collider* mCollider;
    Collider* getCollider();

    void receiveDamage();
    int getHealth();

    int getPosition();

private:
    Animation* mAnimation;
    int mHealth;
    RigidBody* mRigidBody;
};

#endif //DINOCAUST_ENEMY_H
