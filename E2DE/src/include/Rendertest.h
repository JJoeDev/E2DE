#ifndef E2E_RENDER_TEST_H_
#define E2E_RENDER_TEST_H_

#include "Vector.h"
#include <SDL2/SDL_rect.h>

namespace e2e { class Engine; }

namespace e2e::dev{
    class Renderable{
    public:
        Renderable(const Vector&);
        ~Renderable();

        void render(Engine&);

        inline void AddPos(const Vector& v) { r.x += v.x, r.y += v.y; }

    private:
        SDL_Rect r;
    };
}

#endif