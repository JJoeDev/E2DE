#ifndef E2E_CORE_H_
#define E2E_CORE_H_

#include <iostream>
#include <SDL2/SDL.h>

#include "EventManager.h"
#include "Vector.h"

/*
    TODO: Rendering
    IDEAS{
        * Static renderer that every entity can get their hands on
        * Inheritance for gameobjects
        * ECS? (I am not creating my own ECS again. Use EnTT)
        * 
    }
*/

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

        EventManager* _eventManager{nullptr};

        bool _running{ false };
    };
}

#endif