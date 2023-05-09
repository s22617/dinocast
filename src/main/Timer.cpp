#include "Timer.h"
#include "SDL.h"

Timer* Timer::sInstance = nullptr;

void Timer::tick() {
    mDeltaTime = (SDL_GetTicks() - mLastTime) * (FPS/1000.0f);
    if(mDeltaTime > DELTA_TIME) {
        mDeltaTime = DELTA_TIME;
    }
    mLastTime = SDL_GetTicks();
}

Timer::Timer() {

}
