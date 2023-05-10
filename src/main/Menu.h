#ifndef DINOCAUST_MENU_H
#define DINOCAUST_MENU_H

#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

const int SCREEN_WIDTH_2 = 960;
const int SCREEN_HEIGHT_2 = 640;

class Menu {
public:
    bool terminate = false;
    static Menu* getInstance() {
        return sInstance = (sInstance != nullptr) ? sInstance : new Menu();
    }

    bool initializeMenu();
    bool initializeEndScreen(int finalScore);
    bool clean();
    void quit();
    void update();

    void render();
    void events();

    inline SDL_Renderer* getRenderer() {
        return mRenderer;
    }

    inline bool isRunning(){
        return mIsRunning;
    }

private:
    Menu(){}
    bool mIsRunning;

    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    static Menu* sInstance;

};


#endif //DINOCAUST_MENU_H
