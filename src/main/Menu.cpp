#include "Menu.h"
#include "../inputs/Input.h"

#include <iostream>
#include <string>

Menu* Menu::sInstance = nullptr;

SDL_Surface* surfaceMessage1;
SDL_Surface* surfaceMessage2;
SDL_Texture* Message1;
SDL_Rect Message_rect1;
SDL_Texture* Message2;
SDL_Rect Message_rect2;

SDL_Texture* dinoTexture;

bool Menu::initializeMenu() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
        std::cout << "SDL Initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    mWindow = SDL_CreateWindow("Dinocast", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH_2, SCREEN_HEIGHT_2, 0);
    if (mWindow == nullptr) {
        std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRenderer == nullptr) {
        std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Surface* surface = IMG_Load("../assets/dino_logo.png");
    dinoTexture = SDL_CreateTextureFromSurface(mRenderer, surface);

    SDL_Rect dinoSourceRectangle = {0, 0, 114, 96};
    SDL_Rect dinoDestinationRectangle = {SCREEN_WIDTH_2 / 2 - 67, SCREEN_HEIGHT_2 / 2 - 48, 114, 96};

    SDL_RenderCopyEx(mRenderer, dinoTexture, &dinoSourceRectangle, &dinoDestinationRectangle, 0,
                     nullptr, SDL_FLIP_NONE);

    TTF_Init();

    TTF_Font* RobotoCondensed_small = TTF_OpenFont("../assets/RobotoCondensed-Bold.ttf", 40);
    TTF_Font* RobotoCondensed_big = TTF_OpenFont("../assets/RobotoCondensed-Bold.ttf", 80);

    SDL_Color White = {255, 255, 255};

    surfaceMessage1 = TTF_RenderText_Solid(RobotoCondensed_small, "Press SPACE to begin", White);
    Message1 = SDL_CreateTextureFromSurface(mRenderer, surfaceMessage1);

    surfaceMessage2 = TTF_RenderText_Solid(RobotoCondensed_big, "DINOCAST", White);
    Message2 = SDL_CreateTextureFromSurface(mRenderer, surfaceMessage2);

    Message_rect1.x = SCREEN_WIDTH_2 / 2 - 150;
    Message_rect1.y = SCREEN_HEIGHT_2 / 2 + 150;
    Message_rect1.w = 300;
    Message_rect1.h = 60;

    Message_rect2.x = SCREEN_WIDTH_2 / 2 - 150;
    Message_rect2.y = 0;
    Message_rect2.w = 300;
    Message_rect2.h = 100;

    return mIsRunning = true;
}

bool Menu::initializeEndScreen(int finalScore) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
        std::cout << "SDL Initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    mWindow = SDL_CreateWindow("Dinocast", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH_2, SCREEN_HEIGHT_2, 0);
    if (mWindow == nullptr) {
        std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRenderer == nullptr) {
        std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    TTF_Init();

    TTF_Font* RobotoCondensed_small = TTF_OpenFont("../assets/RobotoCondensed-Bold.ttf", 40);
    TTF_Font* RobotoCondensed_big = TTF_OpenFont("../assets/RobotoCondensed-Bold.ttf", 80);

    SDL_Color White = {255, 255, 255};

    std::string scoreMessage = "Your score: " + std::to_string(finalScore);
    surfaceMessage1 = TTF_RenderText_Solid(RobotoCondensed_small, scoreMessage.c_str(), White);
    Message1 = SDL_CreateTextureFromSurface(mRenderer, surfaceMessage1);

    surfaceMessage2 = TTF_RenderText_Solid(RobotoCondensed_big, "DINOCAST", White);
    Message2 = SDL_CreateTextureFromSurface(mRenderer, surfaceMessage2);

    Message_rect1.x = SCREEN_WIDTH_2 / 2 - 150;
    Message_rect1.y = SCREEN_HEIGHT_2 / 2 + 150;
    Message_rect1.w = 300;
    Message_rect1.h = 60;

    Message_rect2.x = SCREEN_WIDTH_2 / 2 - 150;
    Message_rect2.y = 0;
    Message_rect2.w = 300;
    Message_rect2.h = 100;

    return mIsRunning = true;
}

void Menu::update() {
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_SPACE)) {
        quit();
    }
}

bool Menu::clean() {
    SDL_DestroyTexture(dinoTexture);

    SDL_FreeSurface(surfaceMessage1);
    SDL_DestroyTexture(Message1);

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return true;
}

void Menu::quit() {
    mIsRunning = false;
}

void Menu::render() {
    SDL_RenderCopy(mRenderer, Message1, NULL, &Message_rect1);
    SDL_RenderCopy(mRenderer, Message2, NULL, &Message_rect2);

    //TextureHandler::getInstance()->draw("dino", SCREEN_WIDTH_2 / 2, SCREEN_HEIGHT_2 / 2, 114, 96);
    SDL_RenderPresent(mRenderer);
}

void Menu::events() {
    Input::getInstance()->inputListenMenu();
}