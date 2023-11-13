#ifndef E2E_SCENE_H_
#define E2E_SCENE_H_

#include "../../Vendor/ECS/EnTT/src/entt/entt.hpp" // We can just say #include "entt.hpp" but vscodium can't find the header so I do this for now
#include "Components.h"

namespace e2e{
    class Entity;
    class Engine;

    class Scene{
    public:
        Scene();
        ~Scene();

        Entity CreateEntity();

    private:
        entt::registry _registry;

        friend class Entity;
    };
}

#endif
