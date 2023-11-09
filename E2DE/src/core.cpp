#include "include/core.h"
#include "include/EventManager.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

e2e::Engine::Engine(const char* title, int width, int height){
    SDL_Init(SDL_INIT_VIDEO);

    _window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    _eventManager = &e2e::EventManager::GetInstance();

    if (_window && _renderer) _running = true;
}

e2e::Engine::~Engine(){
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void e2e::Engine::DrawRect(const SDL_Rect& r){    
    SDL_RenderDrawRect(_renderer, &r);
}

void e2e::Engine::update(){
    _frameEnd = _frameStart;
    _frameStart = SDL_GetPerformanceCounter();
    _delta = static_cast<double>((_frameStart - _frameEnd) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

    _eventManager->Update();
}

void e2e::Engine::BeginRender(){
    _Clear();
    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
}

void e2e::Engine::EndRender(){
    SDL_SetRenderDrawColor(_renderer, 100, 100, 100, 255);
    _Present();
}

////// PRIVATES //////

void e2e::Engine::_Clear(){
    SDL_RenderClear(_renderer);
}

void e2e::Engine::_Present(){
    SDL_RenderPresent(_renderer);
}