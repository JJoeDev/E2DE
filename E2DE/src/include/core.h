#ifndef E2E_CORE_H_
#define E2E_CORE_H_

#include <iostream>

#include "SDL2/SDL.h"

#include "InputHandler.h"

namespace e2e{
    class Engine{
    public:
        Engine(const char* title, int width, int height);
        ~Engine();

        void update();
        void render();

        inline bool Terminate() { return _inputHandler->OnQuitEvent(); }

    private:
        SDL_Window* _window{ nullptr };
        SDL_Renderer* _renderer{ nullptr };

        InputHandler* _inputHandler{nullptr};

        bool _running{ false };
    };
}

#endif