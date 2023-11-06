#ifndef E2E_EVENT_MANAGER_H_
#define E2E_EVENT_MANAGER_H_

#include <string>
#include <unordered_map>
#include <vector>

#include "InputNames.h"

namespace e2e{
    class EventManager{
    public:
        static EventManager& GetInstance(){
            static EventManager instance;
            return instance;
        }

        EventManager(const EventManager&)   = delete;
        void operator=(const EventManager&) = delete;

        void Update();

        float GetValue(std::string);

        bool Pressed(std::string);
        bool Hold(std::string);
        bool Released(std::string);

        void NewMap(std::string);
        void BindKey(std::string, int, float);

        bool GetQuit();

    private:
        EventManager(){ _quitEvent = false; }

        enum class KeyState : char{
            NONE,
            PRESS,
            HOLD,
            RELEASE
        };

        struct KeyValue{
            KeyValue() : state(KeyState::NONE){}

            int key;
            KeyState state;
            float value;

            std::vector<std::string> maps;
        };

        struct MapState{
            MapState() : state(KeyState::NONE), value(0.0f){}

            float value;
            KeyState state;
        };

        float _value;
        bool _quitEvent;

        std::vector<KeyValue> _keys;
        std::unordered_map<std::string, MapState> _map;
    };
}

#endif