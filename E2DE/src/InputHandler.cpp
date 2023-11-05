#include "include/InputHandler.h"
#include <SDL2/SDL_events.h>
#include <iostream>

e2e::InputHandler::InputHandler(){}
e2e::InputHandler::~InputHandler(){}

void e2e::InputHandler::Update(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT)
            _quitEvent = true;
    }
}