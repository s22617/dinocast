#include "CollisionHandler.h"
#include "../main/Engine.h"
#include "../graphics/TextureHandler.h"
#include <iostream>
CollisionHandler* CollisionHandler::sInstance = nullptr;

CollisionHandler::CollisionHandler() {}

bool CollisionHandler::edgeMapCollisionLeft(SDL_Rect a) {
    bool x_overlaps = (a.x < 0);
    return x_overlaps;
}

bool CollisionHandler::edgeMapCollisionRight(SDL_Rect a) {
    bool x_overlaps = (a.x > 884);
    return x_overlaps;
}

bool CollisionHandler::checkCollision(SDL_Rect a, SDL_Rect b) {
    bool x_overlaps = (a.x < b.x + b.w) && (a.x + a.w > b.x);

    bool y_overlaps = (a.y < b.y + b.h) && (a.y + a.h > b.y);
    return (x_overlaps && y_overlaps);
}

