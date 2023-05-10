#ifndef DINOCAUST_INPUT_H
#define DINOCAUST_INPUT_H

#include "SDL.h"

class Input {
public:
    static Input* getInstance() {
        return sInstance = (sInstance != nullptr) ? sInstance : new Input();
    }
    // listening to keyboard actions
    void inputListen();
    void inputListenMenu();
    bool getKeyDown(SDL_Scancode key);
private:
    Input();
    void keyUp();
    void keyDown();

    const Uint8* mKeyStates;
    static Input* sInstance;
};


#endif //DINOCAUST_INPUT_H
