#include "core.h"

Core::Engine::Engine(){
    std::cout << "Engine constructor called!\n";

    _window = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Core::Engine::~Engine(){
    std::cout << "Engine Deconstructor Called!\n";

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Core::Engine::HelloFunc(){
    SDL_RenderClear(_renderer);
    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    SDL_RenderPresent(_renderer);
}