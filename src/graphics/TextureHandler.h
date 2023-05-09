#ifndef DINOCAUST_TEXTUREHANDLER_H
#define DINOCAUST_TEXTUREHANDLER_H

#include "SDL.h"
#include <string>
#include <map>

class TextureHandler {
    // creating singleton class
public:
    static TextureHandler* getInstance() {return sInstance = (sInstance != nullptr) ? sInstance : new TextureHandler;
    }
    bool load(std::string id, std::string filename);
    void drop(std::string id);
    void clean();

    void draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void drawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);

private:
    TextureHandler() {
    }
    static TextureHandler* sInstance;
    std::map<std::string, SDL_Texture*> mTextureMap;
};


#endif //DINOCAUST_TEXTUREHANDLER_H
