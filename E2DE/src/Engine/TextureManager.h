#ifndef E2E_TEXTURE_MANAGER_H_
#define E2E_TEXTURE_MANAGER_H_

#include <SDL2/SDL_render.h>
#include <memory>

namespace e2e{
    struct TextureManager {
    private:
        static std::shared_ptr<SDL_Texture> LoadTexture(SDL_Renderer*, const char*);

        friend class Engine;
    };
}

#endif