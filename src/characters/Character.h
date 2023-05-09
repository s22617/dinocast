#ifndef DINOCAUST_CHARACTER_H
#define DINOCAUST_CHARACTER_H

#include "../object/GameObject.h"
#include <string>

class Character : public GameObject {
public:
    Character(Properties* properties) : GameObject(properties){}

    Character() {}

    virtual void draw()=0;
    virtual void clean()=0;
    virtual void update(float dt)=0;

protected:
    std::string mName;
    SDL_RendererFlip playerDirection = SDL_FLIP_HORIZONTAL;
};


#endif //DINOCAUST_CHARACTER_H
