#include <iostream>
#include "SDL2/SDL.h"

namespace Core{
    class Engine{
    public:
        Engine();
        ~Engine();

        void HelloFunc();
    private:
        SDL_Window* _window{nullptr};
        SDL_Renderer* _renderer{nullptr};
    };
}