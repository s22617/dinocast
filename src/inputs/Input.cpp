#include "Input.h"
#include "../main/Engine.h"
#include "../main/Menu.h"

Input* Input::sInstance = nullptr;

Input::Input() {
    mKeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::inputListen() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                Engine::getInstance()->quit();
                break;
            case SDL_KEYDOWN:
                keyDown();
                break;
            case SDL_KEYUP:
                keyUp();
                break;
        }
    }
}

void Input::inputListenMenu() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                Menu::getInstance()->terminate = true;
                Menu::getInstance()->quit();
                break;
            case SDL_KEYDOWN:
                keyDown();
                break;
            case SDL_KEYUP:
                keyUp();
                break;
        }
    }
}

bool Input::getKeyDown(SDL_Scancode key) {
    return mKeyStates[key] == 1;
}

void Input::keyUp() {
    mKeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::keyDown() {
    mKeyStates = SDL_GetKeyboardState(nullptr);
}
