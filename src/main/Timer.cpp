#include <iostream>
#include "Timer.h"
#include "SDL.h"

Timer* Timer::sInstance = nullptr;

void Timer::tick() {
    mDeltaTime = (SDL_GetTicks() - mLastTime) * (FPS/1000.0f);
    if(mDeltaTime > MAX_DELTA_TIME) {
        mDeltaTime = MAX_DELTA_TIME;
    }

    mLastTime = SDL_GetTicks();
}

void Timer::delayIfNeeded(float deltaTime) {
    if (deltaTime < TARGET_DELTA_TIME) {
        std::cout << TARGET_DELTA_TIME - deltaTime << std::endl;
        SDL_Delay(15);
    }


}

Timer::Timer() {

}
