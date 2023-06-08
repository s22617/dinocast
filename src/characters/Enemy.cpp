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
}

float Enemy::getPosition() {
    return mTransform->Y;
}

void Enemy::setPosition(float Y) {
    mTransform->Y += Y;
}

int Enemy::getHealth() {
    return mHealth;
}

void Enemy::update(float dt) {
    if (getPosition() < -100) {
        setPosition(2.0f);
    }
    else {
        setPosition(mRigidBody->updateEnemyFalling(dt));
    }
    mCollider->set(mTransform->X, mTransform->Y, 76, 64);

    mAnimation->update();
}

Collider* Enemy::getCollider() {
    return mCollider;
}