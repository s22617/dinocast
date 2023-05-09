#ifndef DINOCAUST_COLLISIONHANDLER_H
#define DINOCAUST_COLLISIONHANDLER_H
#include "SDL.h"

class CollisionHandler {
public:
    bool edgeMapCollisionLeft(SDL_Rect a);
    bool edgeMapCollisionRight(SDL_Rect a);
    bool checkCollision(SDL_Rect a, SDL_Rect b);

    inline static CollisionHandler* getInstance() {
        return sInstance = (sInstance != nullptr) ? sInstance : new CollisionHandler();
    }
private:
    CollisionHandler();
    static CollisionHandler* sInstance;
};


#endif //DINOCAUST_COLLISIONHANDLER_H
