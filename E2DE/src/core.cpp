#include "core.h"

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

    void Engine::DrawRect(const SDL_Rect& r){    
        SDL_RenderDrawRect(_renderer, &r);
    }

    void Engine::update(){
        _frameEnd = _frameStart;
        _frameStart = SDL_GetPerformanceCounter();
        _delta = static_cast<double>((_frameStart - _frameEnd) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

        _eventManager->Update();
    }

    void Engine::BeginRender(){
        _Clear();
        SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    }

    void Engine::EndRender(){
        SDL_SetRenderDrawColor(_renderer, 100, 100, 100, 255);
        _Present();
    }

    ////// PRIVATES //////

    void Engine::_Clear(){
        SDL_RenderClear(_renderer);
    }

    void Engine::_Present(){
        SDL_RenderPresent(_renderer);
    }
}
