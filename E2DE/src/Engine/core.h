#ifndef E2E_CORE_H_
#define E2E_CORE_H_

#include <iostream>
#include <sys/types.h>

#include <SDL2/SDL.h>

#include "../Events/EventManager.h"
#include "../Scene/Scene.h"
#include "../Math/Vector.h"
#include "TextureManager.h"

#include <filesystem>

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <Windows.h>
#endif

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

        inline Scene& GetScene() { return _scene; }

        inline void SetBgColor(const Vector4& color) { _bgColor = color; }

        inline void SetAssetPath(const std::filesystem::path& path) { _assetPath = path; }
        inline std::string GetAssetPath() { return _assetPath; }
        const std::filesystem::path GetPath() const;
        
        void LoadTexture(SpriteRendererComponent&, const std::string& path) const;

        bool checkCollisions(const AABBCollisionBox&, const TransformComponent&, const AABBCollisionBox&, const TransformComponent&);

        void Update();
        void Render();

    private:
        void _Clear();
        void _Present();

        std::filesystem::path _assetPath;

        SDL_Window* _window{ nullptr };
        SDL_Renderer* _renderer{ nullptr };

        EventManager* _eventManager{nullptr};

        Scene _scene;

        Vector _windowSize{};
        Vector4 _bgColor{ 20.0f, 20.0f, 20.0f, 255.0f };

        unsigned long _frameStart{0};
        unsigned long _frameEnd{0};
        double _delta{0};

        bool _running{ false };
    };
}

#endif