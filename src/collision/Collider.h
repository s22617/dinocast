#ifndef DINOCAUST_COLLIDER_H
#define DINOCAUST_COLLIDER_H

#include "SDL.h"

class Collider {
public:
    inline SDL_Rect get() {
        return mBox;
    }
    inline void setBuffer(int x, int y, int w, int h) {
        mBuffer = {x, y, w, h};
    }

    void set(int x, int y, int w, int h) {
        mBox = {x - mBuffer.x, y - mBuffer.y, w - mBuffer.w, h - mBuffer.h};
        //std::cout << mBox.x << " " << mBox.y << std::endl;
    }
private:
    SDL_Rect mBox;
    SDL_Rect mBuffer;
};

#endif //DINOCAUST_COLLIDER_H
