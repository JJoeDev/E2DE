#include "TextureManager.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "../../Vendor/stb/stb_image.h"

namespace e2e{
    std::shared_ptr<SDL_Texture> TextureManager::LoadTexture(SDL_Renderer* renderer, const char* path){
        int width, height, channels;
        stbi_uc* pixels = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);

        if(!pixels){
            std::cerr << "ERROR: could not load image!\n";
            return nullptr;
        }

        SDL_Texture* tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width, height);
        SDL_UpdateTexture(tex, nullptr, pixels, width * sizeof(uint32_t));

        stbi_image_free(pixels);

        if(!tex){
            std::cerr << "ERROR: could not create texture\n";
            return nullptr;
        }

        return std::shared_ptr<SDL_Texture>(tex, SDL_DestroyTexture);
    }
}