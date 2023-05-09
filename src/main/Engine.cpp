#include "Engine.h"
#include "../physics/Vector2D.h"
#include "../characters/Dino.h"
#include "../graphics/TextureHandler.h"
#include "../inputs/Input.h"
#include "../main/Timer.h"
#include "../util/NumberGenerator.h"

#include <iostream>
#include <vector>

Engine* Engine::sInstance = nullptr;
Dino* player = nullptr;
std::vector<Enemy*> enemies;

bool Engine::initialize() {

    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
        std::cout << "SDL Initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    mWindow = SDL_CreateWindow("Dinocast", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (mWindow == nullptr) {
        std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRenderer == nullptr) {
        std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }
    TextureHandler::getInstance()->load("ground", "../assets/ground.png");

    TextureHandler::getInstance()->load("player", "../assets/dino_idle_bigger.png");
    TextureHandler::getInstance()->load("player_walk", "../assets/dino_walk_bigger.png");

    for (int i = 1; i < 51; i++) {
        std::string textureId = "enemy" + std::to_string(i);
        TextureHandler::getInstance()->load(textureId, "../assets/enemy_falling.png");
        enemies.push_back(new Enemy(new Properties(textureId, NumberGenerator::getInstance()->getRandPosX(), (i * -150) + NumberGenerator::getInstance()->getRandPosY(), 35, 32), 100));
    }

    player = new Dino(new Properties("player", 100, 476, 76, 64), enemies);

    return mIsRunning = true;
}

bool Engine::clean() {
    TextureHandler::getInstance()->clean();
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
    return true;
}

void Engine::quit() {
    mIsRunning = false;
}

void Engine::update() {
    float deltaTime = Timer::getInstance()->getDeltaTime();
    player->update(deltaTime);
    for (int i = 0; i < enemies.size(); i++) {
        enemies.at(i)->update(deltaTime);
    }
//    enemy->update(deltaTime);
//    enemy2->update(deltaTime);
}

void Engine::render() {
    SDL_SetRenderDrawColor(mRenderer, 124, 169, 69, 255);
    // We need to clear the renderer everytime before presenting it
    SDL_RenderClear(mRenderer);
    TextureHandler::getInstance()->draw("ground", 0, 540, 960, 100);

    player->draw();
    for (int i = 0; i < enemies.size(); i++) {
        enemies.at(i)->draw();
    }

//    enemy->draw();
//    enemy2->draw();
    SDL_RenderPresent(mRenderer);
}

void Engine::events() {
//    SDL_Event event;
//    SDL_PollEvent(&event);
//    switch(event.type) {
//        case SDL_QUIT:
//            quit();
//            break;
//    }
    Input::getInstance()->inputListen();
}
