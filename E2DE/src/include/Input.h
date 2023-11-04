#ifndef E2E_INPUT_H_
#define E2E_INPUT_H_

#include <vector>

#include "InputNames.h"

namespace e2e{
    enum class KeyState : char{ // Max of 8 flags
        KEY_NONE = 1 << 0,      // 0001
        KEY_PRESSED = 1 << 1,   // 0010 
        KEY_RELEASED = 1 << 2,  // 0100
        KEY_HOLD = 1 << 3       // 1000
    };

    class InputManager{
    public:
        InputManager(){}
        virtual ~InputManager();

        void Update();

        float GetValue(std::string map);
        bool Pressed(std::string map);
        bool Hold(std::string map);
        bool Released(std::string map);

        void NewMap(std::string map);
        void BindKey(std::string map, int key, float value);

        bool EventQuit();

    private:
        struct _InputValue{
            _InputValue(){}

            int key;
            char status;
            float value;

            std::vector<std::string> maps{};
        };

        struct _MapStatus{
            _MapStatus() : value(0.0f), status(static_cast<char>(KeyState::KEY_NONE)){}

            float value;
            char status;
        };

        inline void _SetState(char& set, KeyState state) { 
            if (!_CheckState(set, state))
                set |= static_cast<char>(state);
        }

        inline void _RemoveState(char& set, KeyState state) { 
            if (_CheckState(set, state))
                set &= ~static_cast<char>(state);
        }

        inline bool _CheckState(char& check, KeyState state) { return check & static_cast<char>(state); }

        float _value{};
        bool _eventQuit{false};

        std::vector<_InputValue> _keys{};
        std::unordered_map<std::string, _MapStatus> _map;
    };
}

#endif