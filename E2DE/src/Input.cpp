#include "include/Input.h"

#include <SDL2/SDL_events.h>

e2e::InputManager::~InputManager(){

}

void e2e::InputManager::Update() {
    for(auto& obj : _map){
        obj.second.value = 0.0f;
        _SetState(obj.second.status, KeyState::KEY_NONE);
    }

    for (auto& obj : _keys){
        if (_CheckState(obj.status, KeyState::KEY_RELEASED)){
            _RemoveState(obj.status, KeyState::KEY_RELEASED);
            _SetState(obj.status, KeyState::KEY_NONE);
        }
        else if (_CheckState(obj.status, KeyState::KEY_PRESSED)){
            _RemoveState(obj.status, KeyState::KEY_PRESSED);
            _SetState(obj.status, KeyState::KEY_HOLD);
        }
    }

    SDL_Event e;
    while(SDL_PollEvent(&e)){
        for (auto& obj : _keys){
            if(obj.key == e.key.keysym.sym){
                if (e.type == SDL_KEYDOWN)
                    _SetState(obj.status, KeyState::KEY_PRESSED);
                else if (e.type == SDL_KEYUP)
                    _SetState(obj.status, KeyState::KEY_RELEASED);
            }
        }

        if (e.type == SDL_QUIT)
            _eventQuit = true;
    }
}

float e2e::InputManager::GetValue(std::string map){
    return _map[map].value;
}

bool e2e::InputManager::Pressed(std::string map){
    return _CheckState(_map[map].status, KeyState::KEY_PRESSED);
}

bool e2e::InputManager::Hold(std::string map){
    return _CheckState(_map[map].status, KeyState::KEY_HOLD);
}

bool e2e::InputManager::Released(std::string map){
    return _CheckState(_map[map].status, KeyState::KEY_RELEASED);
}

void e2e::InputManager::NewMap(std::string map){
    _map[map] = _MapStatus();
}

void e2e::InputManager::BindKey(std::string map, int key, float value){
    for(auto& obj : _keys){
        if(obj.key == key){
            obj.maps.emplace_back(map);
            return;
        }
    }

    _keys.emplace_back(_InputValue());

    _keys.back().key = key;
    _keys.back().value = value;
    _keys.back().maps.emplace_back(map);
}

bool e2e::InputManager::EventQuit(){
    return _eventQuit;
}