#ifndef DINOCAUST_GAMEOBJECT_H
#define DINOCAUST_GAMEOBJECT_H

#endif //DINOCAUST_GAMEOBJECT_H

#include <SDL.h>
#include "Object.h"
#include "../physics/Transform.h"

struct Properties {
public:
    Properties(std::string textureId, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
            : textureId(textureId), width(width), height(height), x(x), y(y), flip(flip) {}

public:
    std::string textureId;
    int width, height;
    float x, y;
    SDL_RendererFlip flip;
};

// class that will be inherited by classes like Player, Enemy etc.
class GameObject : public Object {
public:
    GameObject(Properties* p) : mTextureId(p->textureId), mWidth(p->width), mHeight(p->height),
    mFlip(p->flip) {
        mTransform = new Transform(p->x, p->y);
    }

    GameObject() {}

    virtual void draw()=0;
    virtual void update(float dt)=0;
    virtual void clean()=0;

protected:
    int mWidth, mHeight;
    std::string mTextureId;
    SDL_RendererFlip mFlip;
    Transform* mTransform;
};