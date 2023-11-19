#ifndef E2E_ENTITY_H_
#define E2E_ENTITY_H_

#include "Scene.h"

#include "../../Vendor/ECS/EnTT/src/entt/entt.hpp" 

#include <assert.h>

namespace e2e{
    class Entity{
    public:
        Entity() = default;
        Entity(entt::entity handle, Scene* scene) : _entityHandle(handle), _scene(scene) { }
        Entity(const Entity& other) = default;

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args){
            assert(!HasComponent<T>() && "Entity already has this component");

            return _scene->_registry.emplace<T>(_entityHandle, std::forward<Args>(args)...);
        }

        template<typename T>
        T& GetComponent(){
            assert(HasComponent<T>() && "Entity does not have this component");

            return _scene->_registry.get<T>(_entityHandle);
        }

        template<typename T>
        bool HasComponent(){
            return _scene->_registry.any_of<T>(_entityHandle);
        }

        template<typename T>
        void RemoveComponent(){
            assert(HasComponent<T>() && "Entity does not have this component");

            _scene->_registry.remove<T>(_entityHandle);
        }

        operator bool() const { return _entityHandle != entt::null; }

    private:
        entt::entity _entityHandle{ entt::null };
        Scene* _scene = nullptr; // 12 bytes
    };
}

#endif