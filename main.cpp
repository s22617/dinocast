#include "src\main\Engine.h"
#include "src\main\Timer.h"

#define SDL_MAIN_HANDLED

int main() {

    Engine::getInstance()->initialize();


    while(Engine::getInstance()->isRunning()) {
        Engine::getInstance()->events();
        Engine::getInstance()->update();
        Engine::getInstance()->render();
        Timer::getInstance()->tick();
    }

    Engine::getInstance()->clean();

//    SDL_Init(SDL_INIT_EVERYTHING);
//    auto window = SDL_CreateWindow("Okienko SDL",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640, 480,SDL_WINDOW_SHOWN);
//    SDL_Delay(2000);
//    SDL_DestroyWindow(window);
//    SDL_Quit();

    return 0;
}
