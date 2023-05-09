#ifndef DINOCAUST_ANIMATION_H
#define DINOCAUST_ANIMATION_H
#include "SDL.h"
#include <string>

class Animation {
public:
    Animation(){}
    void update();
    void draw(float x, float y, int spriteWidth, int spriteHeight);
    void setProperties(std::string textureId, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    int mSpriteRow, mSpriteFrame;
    int mAnimationSpeed, mFrameCount;
    std::string mTextureId;
    SDL_RendererFlip mFlip;
};


#endif //DINOCAUST_ANIMATION_H
