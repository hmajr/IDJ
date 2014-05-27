#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

namespace GameEngine {
class Resource
{
    union ResourcePtr{
        SDL_Texture *texture;
        Mix_Music *music;
        Mix_Chunk *chunk;
        TTF_Font *font;
    };

public:
    int userCount;
    ResourcePtr data;
};
}