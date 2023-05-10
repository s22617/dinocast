#include "Dino.h"
#include "../graphics/TextureHandler.h"
#include "../inputs/Input.h."
#include "../collision/CollisionHandler.h"

Dino::Dino(Properties *props, std::vector<Enemy*> *enemies) : Character(props) {
    mEnemies = enemies;
    mScore = 0;

    mCollider = new Collider();
    mCollider->setBuffer(0, 0, 0, 0);

    mRigidBody = new RigidBody();

    mAnimation = new Animation();
    mAnimation->setProperties(mTextureId, 0, 2, 600);
}

void Dino::draw() {
    mAnimation->draw(mTransform->X, mTransform->Y, mWidth, mHeight);
}

void Dino::clean() {
    TextureHandler::getInstance()->drop(mTextureId);
}

void Dino::update(float dt) {
    mAnimation->setProperties("player", 0, 2, 600, Dino::playerDirection);
    mRigidBody->unsetForce();
    // WALKING
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_LEFT)) {
        Dino::playerDirection = SDL_FLIP_NONE;
        mAnimation->setProperties("player_walk", 0, 2, 120, Dino::playerDirection);
        mRigidBody->applyForceX(-8);
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_RIGHT)) {
        Dino::playerDirection = SDL_FLIP_HORIZONTAL;
        mAnimation->setProperties("player_walk", 0, 2, 120, Dino::playerDirection);
        mRigidBody->applyForceX(8);
    }

//  ATTACK
    if (!mEnemies->empty()) {
        for (unsigned int i = 0; i < mEnemies->size(); i++) {
            Enemy* currentEnemy = mEnemies->at(i);
            //std::cout << currentEnemy->getPosition() << std::endl;
            if (currentEnemy->getPosition() > 700) {
                currentEnemy->clean();
                mEnemies->erase(mEnemies->begin()+i);
            }
            else if (Input::getInstance()->getKeyDown(SDL_SCANCODE_SPACE)) {
                if (CollisionHandler::getInstance()->checkCollision(mCollider->get(), mEnemies->at(i)->getCollider()->get())) {
                    currentEnemy->receiveDamage();
                    if (currentEnemy->getHealth() < 0) {
                        currentEnemy->clean();
                        mEnemies->erase(mEnemies->begin()+i);
                        mScore += 1;
                    }
                }
            }
        }
    }

    mRigidBody->update(dt);

    mTransform->X += mRigidBody->getPosition().X;
    mCollider->set(mTransform->X, mTransform->Y, 76, 64);

    if (CollisionHandler::getInstance()->edgeMapCollisionLeft(mCollider->get())) {
        mTransform->X = 0;
    }
    if (CollisionHandler::getInstance()->edgeMapCollisionRight(mCollider->get())) {
        mTransform->X = 884;
    }

    mTransform->TranslateX(mRigidBody->getPosition().X);

    mAnimation->update();
}

int Dino::getScore() {
    return mScore;
}
