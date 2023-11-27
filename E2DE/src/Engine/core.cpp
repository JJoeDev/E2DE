#include "core.h"
#include "TextureManager.h"
#include <SDL2/SDL_render.h>
#include <cstdint>
#include <filesystem>
#include <stdexcept>
#include <unistd.h>
#include <vector>

namespace e2e{
    Engine::Engine(const char* title, int width, int height, u_int32_t flags){
        _windowSize.x = width;
        _windowSize.y = height;

        SDL_Init(SDL_INIT_VIDEO);

        _window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

        _eventManager = &EventManager::GetInstance();

        if (_window && _renderer) _running = true;
    }

    Engine::~Engine(){
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    void Engine::LoadTexture(SpriteRendererComponent& SRC, const std::string& path) const {
        SRC.texture = TextureManager::LoadTexture(_renderer, path.c_str());
    }

    bool Engine::checkCollisions(const AABBCollisionBox& col1, const TransformComponent& t1, const AABBCollisionBox& col2, const TransformComponent& t2){
        bool colX = t1.Position.x + col1.size.x >= t2.Position.x && t2.Position.x + col2.size.x >= t1.Position.x;
        bool colY = t1.Position.y + col1.size.y >= t2.Position.y && t2.Position.y + col2.size.y >= t1.Position.y;

        return colX && colY;
    }

    void Engine::Update(){
        _frameEnd = _frameStart;
        _frameStart = SDL_GetPerformanceCounter();
        _delta = static_cast<double>((_frameStart - _frameEnd) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

        _eventManager->Update();

        auto view = _scene._registry.view<TransformComponent, AABBCollisionBox>();
        for (auto e : view) {
            auto& transform = view.get<TransformComponent>(e);
            auto& aabb = view.get<AABBCollisionBox>(e);

            for(auto e2 : view){
                auto& transform2 = view.get<TransformComponent>(e2);
                auto& aabb2 = view.get<AABBCollisionBox>(e2);

                if (e == e2) continue;
                if(aabb.collisionLayer != aabb2.collisionLayer) continue;
                if (checkCollisions(aabb, transform, aabb2, transform2)){
                    aabb.didCollide = true;
                    aabb2.didCollide = true;
                }
            }
        }
    }

    void Engine::Render(){
        _Clear();

        auto view = _scene._registry.view<SpriteRendererComponent, TransformComponent>();
        for(auto e : view){
            auto& transform = view.get<TransformComponent>(e);
            auto& renderComp = view.get<SpriteRendererComponent>(e);

            SDL_Rect r = {(int)transform.Position.x, (int)transform.Position.y, (int)transform.Scale.x, (int)transform.Scale.y};

            auto& col = view.get<SpriteRendererComponent>(e).color;

            SDL_SetRenderDrawColor(_renderer, col.x, col.y, col.w, col.h);
            SDL_RenderDrawRect(_renderer, &r);

            if(transform.Rotation >= 360.0f) transform.Rotation = 0.0f;
            if(transform.Rotation <= -360.0f) transform.Rotation = 0.0f;

            if(renderComp.texture){
                SDL_Texture* tex = renderComp.texture.get();
                SDL_RenderCopyEx(_renderer, tex, nullptr, &r, transform.Rotation, nullptr, SDL_FLIP_NONE);
            }
        }

        _Present();
    }

    const std::filesystem::path Engine::GetPath() const {
#ifdef __linux__
        char buffer[2048];
        ssize_t count = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);

        if(count != -1){
            buffer[count] = '\0';
            return std::filesystem::canonical(buffer).parent_path().string();
        }
        else throw std::runtime_error("E2E ERROR: Unable to get path to executable!");
#elif _WIN32
        char buffer[2048];
        GetModuleFileNameA(nullptr, buffer, sizeof(buffer));
        return std::filesystem::canonical(buffer);
#endif
    }

    ////// PRIVATES //////

    void Engine::_Clear(){
        SDL_RenderClear(_renderer);
    }

    void Engine::_Present(){
        SDL_SetRenderDrawColor(_renderer, _bgColor.x, _bgColor.y, _bgColor.w, _bgColor.h);
        SDL_RenderPresent(_renderer);
    }
}
