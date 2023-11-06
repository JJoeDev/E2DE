#ifndef E2E_CORE_H_
#define E2E_CORE_H_

#include <iostream>

#include "EventManager.h"
#include "SDL2/SDL.h"

namespace e2e{
    class Engine{
    public:
        Engine(const char* title, int width, int height);
        ~Engine();

        inline EventManager* GetEventInstance() { return _eventManager; }

        inline bool Terminate() { return _eventManager->GetQuit(); }

        void update();
        void render();

    private:
        SDL_Window* _window{ nullptr };
        SDL_Renderer* _renderer{ nullptr };

        EventManager* _eventManager;

        bool _running{ false };
    };
}

#endif