#include "include/core.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

e2e::Engine::Engine(const char* title, int width, int height){
    SDL_Init(SDL_INIT_VIDEO);

    _window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (_window && _renderer) _running = true;
}

e2e::Engine::~Engine(){
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void e2e::Engine::update(){
    _inputHandler->Update();
}

void e2e::Engine::render(){
    SDL_RenderClear(_renderer);
    SDL_SetRenderDrawColor(_renderer, 100, 100, 100, 255);
    SDL_RenderPresent(_renderer);
}