#include "EventManager.h"
#include <SDL2/SDL_events.h>

namespace e2e{
    void EventManager::Update(){
        for(auto& obj : _map){
            obj.second.value = 0.0f;
            obj.second.state = KeyState::NONE;
        }

        for(auto& k : _keys){
            if(k.state == KeyState::RELEASE)
                k.state = KeyState::NONE;
            else if(k.state == KeyState::PRESS)
                k.state = KeyState::HOLD;
        }

        SDL_Event e;
        while(SDL_PollEvent(&e)){
            for(auto& k : _keys){
                if(k.key == e.key.keysym.sym){
                    if(e.type == SDL_KEYDOWN)
                        k.state = KeyState::PRESS;
                    else if(e.type == SDL_KEYUP)
                        k.state = KeyState::RELEASE;
                }
            }

            if(e.type == SDL_QUIT) _quitEvent = true;
        }

        for(auto& k : _keys){
            for(auto& map : k.maps){
                if(k.state == KeyState::HOLD || k.state == KeyState::PRESS)
                    _map[map].value += k.value;

                if(_map[map].state == KeyState::NONE || _map[map].state == KeyState::HOLD)
                    _map[map].state = k.state;
            }
        }
    }

    float EventManager::GetValue(std::string map){
        return _map[map].value;
    }

    bool EventManager::Pressed(std::string map){
        return _map[map].state == KeyState::PRESS;
    }

    bool EventManager::Hold(std::string map){
        return _map[map].state == KeyState::HOLD;
    }

    bool EventManager::Released(std::string map){
        return _map[map].state == KeyState::RELEASE;
    }

    void EventManager::NewMap(std::string map){
        _map[map] = MapState();
    }

    void EventManager::BindKey(std::string map, int key, float value){
        for(auto& k : _keys){
            if(k.key == key){
                k.maps.emplace_back(map);
                return;
            }
        }

        _keys.emplace_back(KeyValue());

        _keys.back().key = key;
        _keys.back().value = value;
        _keys.back().maps.emplace_back(map);
    }

    bool EventManager::GetQuit(){
        return _quitEvent;
    }
}
