#include "core.h"
#include <SDL2/SDL_render.h>

namespace e2e{
    Engine::Engine(const char* title, int width, int height, u_int32_t flags){
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

    void Engine::update(){
        _frameEnd = _frameStart;
        _frameStart = SDL_GetPerformanceCounter();
        _delta = static_cast<double>((_frameStart - _frameEnd) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

        _eventManager->Update();
    }

    void Engine::Render(){
        _Clear();

        auto view = _scene._registry.view<SpriteRendererComponent, TransformComponent>();
        for(auto e : view){
            auto& position = view.get<TransformComponent>(e).Position;
            auto& scale = view.get<TransformComponent>(e).Scale;

            SDL_Rect r = {(int)position.x, (int)position.y, (int)scale.x, (int)scale.y};

            auto& col = view.get<SpriteRendererComponent>(e).color;

            SDL_SetRenderDrawColor(_renderer, col.x, col.y, col.w, col.h);

            SDL_RenderDrawRect(_renderer, &r);
        }

        _Present();
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
