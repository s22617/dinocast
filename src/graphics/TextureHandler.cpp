#include "TextureHandler.h"
#include "..\main\Engine.h"
#include "SDL_image.h"
#include <iostream>

TextureHandler* TextureHandler::sInstance = nullptr;

bool TextureHandler::load(std::string id, std::string filename) {
    //we need a surface to load textures in
    SDL_Surface* surface = IMG_Load(filename.c_str());

    if(surface == nullptr) {
        std::cout << "Texture loading failed: " << filename.c_str() << ", " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), surface);
    if (texture == nullptr) {
        std::cout << "Creating texture from surface failed: " << SDL_GetError() << std::endl;
        return false;
    }
    mTextureMap[id] = texture;
    return true;
}

void TextureHandler::drop(std::string id) {
    SDL_DestroyTexture(mTextureMap[id]);
    mTextureMap.erase(id);
}

void TextureHandler::clean() {
    std::map<std::string, SDL_Texture*>::iterator i;
    for(i = mTextureMap.begin(); i != mTextureMap.end(); i++) {
        SDL_DestroyTexture(i->second);
    }
    mTextureMap.clear();
}

void TextureHandler::draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip) {
    SDL_Rect sourceRectangle = {0, 0, width, height};
    SDL_Rect destinationRectangle = {x, y, width, height};

    SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), mTextureMap[id], &sourceRectangle, &destinationRectangle, 0,
                     nullptr, flip);
}

void TextureHandler::drawFrame(std::string id, int x, int y, int width, int height, int row, int frame,
                               SDL_RendererFlip flip) {
    SDL_Rect sourceRectangle = {width*frame, height*row, width, height};
    SDL_Rect destinationRectangle = {x, y, width, height};

    SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), mTextureMap[id], &sourceRectangle, &destinationRectangle, 0,
                     nullptr, flip);
}
