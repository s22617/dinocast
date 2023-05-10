#include "src\main\Engine.h"
#include "src\main\Timer.h"
#include "src\main\Menu.h"

#define SDL_MAIN_HANDLED

int main() {

    Menu::getInstance()->initializeMenu();
    while(Menu::getInstance()->isRunning()) {
        Menu::getInstance()->events();
        Menu::getInstance()->update();
        Menu::getInstance()->render();
    }
    Menu::getInstance()->clean();

    int finalScore = 0;
    if (!Menu::getInstance()->terminate) {
        Engine::getInstance()->initialize();
        while (Engine::getInstance()->isRunning()) {
            Engine::getInstance()->events();
            Engine::getInstance()->update();
            Engine::getInstance()->render();
            Timer::getInstance()->tick();
        }
        finalScore = Engine::getInstance()->getFinalScore();
        Engine::getInstance()->clean();

        Menu::getInstance()->initializeEndScreen(finalScore);
        while (Menu::getInstance()->isRunning()) {
            Menu::getInstance()->events();
            Menu::getInstance()->update();
            Menu::getInstance()->render();
        }
        Menu::getInstance()->clean();
    }

    return 0;
}
