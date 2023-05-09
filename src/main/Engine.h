#ifndef DINOCAUST_ENGINE_H
#define DINOCAUST_ENGINE_H
#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "SDL_image.h"

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

class Engine {
    public:
        static Engine* getInstance() {
            return sInstance = (sInstance != nullptr) ? sInstance : new Engine();
        }

        bool initialize();
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
        Engine(){}
        bool mIsRunning;

        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;
        static Engine* sInstance;
};


#endif //DINOCAUST_ENGINE_H
