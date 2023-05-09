#include "Animation.h"
#include "../graphics/TextureHandler.h"

void Animation::update() {
    mSpriteFrame = (SDL_GetTicks()/mAnimationSpeed) % mFrameCount;
}

void Animation::draw(float x, float y, int spriteWidth, int spriteHeight) {
    TextureHandler::getInstance()->drawFrame(mTextureId, x, y, spriteWidth, spriteHeight, mSpriteRow, mSpriteFrame, mFlip);
}

void Animation::setProperties(std::string textureId, int spriteRow, int frameCount, int animationSpeed,
                              SDL_RendererFlip flip) {
    mTextureId = textureId;
    mSpriteRow = spriteRow;
    mFrameCount = frameCount;
    mAnimationSpeed = animationSpeed;
    mFlip = flip;
}
