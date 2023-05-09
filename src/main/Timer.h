#ifndef DINOCAUST_TIMER_H
#define DINOCAUST_TIMER_H

const int FPS = 60;
const float DELTA_TIME = 1.5f;

class Timer {
public:
    inline static Timer* getInstance() {
        return sInstance = (sInstance != nullptr) ? sInstance : new Timer();
    }
    void tick();
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
