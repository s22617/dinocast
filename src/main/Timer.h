#ifndef DINOCAUST_TIMER_H
#define DINOCAUST_TIMER_H

const int FPS = 60;
const float MAX_DELTA_TIME = 1.5f;
const float TARGET_DELTA_TIME = 1000 /60;

class Timer {
public:
    inline static Timer* getInstance() {
        return sInstance = (sInstance != nullptr) ? sInstance : new Timer();
    }
    void tick();
    void delayIfNeeded(float deltaTime);
    inline float getDeltaTime() {
        return mDeltaTime;
    };

private:
    Timer();
    static Timer* sInstance;
    float mDeltaTime;
    float mLastTime;
};


#endif //DINOCAUST_TIMER_H
