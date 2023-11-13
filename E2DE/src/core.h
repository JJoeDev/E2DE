#ifndef E2E_CORE_H_
#define E2E_CORE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <sys/types.h>

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

enum WINDOW_FLAG{
    FULLSCREEN         = SDL_WINDOW_FULLSCREEN,
    OPENGL             = SDL_WINDOW_OPENGL,
    SHOWN              = SDL_WINDOW_SHOWN,
    HIDDEN             = SDL_WINDOW_HIDDEN,
    BORDERLESS         = SDL_WINDOW_BORDERLESS,
    RESIZABLE          = SDL_WINDOW_RESIZABLE,
    MINIMIZED          = SDL_WINDOW_MINIMIZED,
    MAXIMIZED          = SDL_WINDOW_MAXIMIZED,
    MOUSE_GRABBED      = SDL_WINDOW_MOUSE_GRABBED,
    INPUT_FOCUS        = SDL_WINDOW_INPUT_FOCUS,
    MOUSE_FOCUS        = SDL_WINDOW_MOUSE_FOCUS,
    FULLSCREEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP,
    FOREIGN            = SDL_WINDOW_FOREIGN,
    ALLOW_HIGHDPI      = SDL_WINDOW_ALLOW_HIGHDPI,
    MOUSE_CAPTURE      = SDL_WINDOW_MOUSE_CAPTURE,
    ALWAYS_ON_TOP      = SDL_WINDOW_ALWAYS_ON_TOP,
    SKIP_TASKBAR       = SDL_WINDOW_SKIP_TASKBAR,
    UTILITY            = SDL_WINDOW_UTILITY,
    TOOLTIP            = SDL_WINDOW_TOOLTIP,
    POPUP_MENU         = SDL_WINDOW_POPUP_MENU,
    KEYBOARD_GRABBED   = SDL_WINDOW_KEYBOARD_GRABBED,
    VULKAN             = SDL_WINDOW_VULKAN,
    METAL              = SDL_WINDOW_METAL    
};

namespace e2e{
    class Engine{
    public:
        Engine(const char* title, int width, int height, u_int32_t flags);
        ~Engine();

        inline EventManager* GetEventInstance() { return _eventManager; }

        inline bool Terminate() { return _eventManager->GetQuit(); }

        inline float GetDeltaTime() { return _delta; }

        void update();

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