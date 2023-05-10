#ifndef DINOCAUST_DINO_H
#define DINOCAUST_DINO_H

#include <vector>
#include "../animation/Animation.h"
#include "../physics/RigidBody.h"
#include "../collision/Collider.h"
#include "Enemy.h"
#include "Character.h"

class Dino : public Character {
public:
    Dino(Properties* p, std::vector<Enemy*> *enemies);

    virtual void draw();
    virtual void clean();
    virtual void update(float dt);

    int getScore();

private:
    std::vector<Enemy*> *mEnemies;
    int mScore;

    Animation* mAnimation;
    RigidBody* mRigidBody;

    Collider* mCollider;
};


#endif //DINOCAUST_DINO_H
