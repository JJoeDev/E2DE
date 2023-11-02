#include <iostream>
#include "SDL2/SDL.h"

namespace e2e{
    class Engine{
    public:
        Engine(const char* title, int width, int height);
        ~Engine();

        inline bool& isRunning() { return _running; }

        void update();
        void render();

    private:
        SDL_Window* _window{ nullptr };
        SDL_Renderer* _renderer{ nullptr };

        bool _running{ false };
    };
}