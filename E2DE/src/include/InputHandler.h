#ifndef E2E_INPUT_HANDLER_H_
#define E2E_INPUT_HANDLER_H_

#include "InputNames.h"

// Starting by making a simple input system
// It will not be a singleton because I am currently too stupid to create a singleton that works without a segfault

namespace e2e{
    class InputHandler{
    public:
        InputHandler();
        virtual ~InputHandler();

        void Update();

        inline bool OnQuitEvent() { return _quitEvent; }

    private:
        enum KeyState{
            NONE,
            PRESSED,
            HOLD,
            RELEASED
        };

        bool _quitEvent{false};
    };
}

#endif