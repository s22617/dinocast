#include "Enemy.h"
#include "../graphics/TextureHandler.h"

Enemy::Enemy(Properties *p, int health) : Character(p) {
    mHealth = health;
    mRigidBody = new RigidBody();
    mCollider = new Collider();
    mCollider->setBuffer(0, 0, 0, 0);

    mAnimation = new Animation();

    mAnimation->setProperties(mTextureId, 0, 2, 300);
}

void Enemy::draw() {
    mAnimation->draw(mTransform->X, mTransform->Y, mWidth, mHeight);
}

void Enemy::clean() {
    TextureHandler::getInstance()->drop(mTextureId);
}

void Enemy::receiveDamage() {
    mHealth -= 50;
    std::cout << mHealth << std::endl;
}

int Enemy::getHealth() {
    return mHealth;
}

void Enemy::update(float dt) {
    mTransform->Y += 1.5;
    mCollider->set(mTransform->X, mTransform->Y, 76, 64);
    mRigidBody->update(dt);

    mAnimation->update();
}

Collider* Enemy::getCollider() {
    return mCollider;
}