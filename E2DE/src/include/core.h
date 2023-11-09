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
        * Forward declaration
    }
*/

namespace e2e{
    class Engine{
    public:
        Engine(const char* title, int width, int height);
        ~Engine();

        inline EventManager* GetEventInstance() { return _eventManager; }

        inline bool Terminate() { return _eventManager->GetQuit(); }

        inline float GetDeltaTime() { return _delta; }

        void DrawRect(const SDL_Rect&);

        void update();
        void BeginRender();
        void EndRender();

    private:
        void _Clear();
        void _Present();

        SDL_Window* _window{ nullptr };
        SDL_Renderer* _renderer{ nullptr };

        EventManager* _eventManager{nullptr};

        unsigned long _frameStart{0};
        unsigned long _frameEnd{0};
        double _delta{0};

        bool _running{ false };
    };
}

#endif