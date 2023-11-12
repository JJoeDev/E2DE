#ifndef E2E_SCENE_H_
#define E2E_SCENE_H_

#include "../../Vendor/ECS/EnTT/src/entt/entt.hpp"

namespace e2e{
    class Scene{
    public:
        Scene();
        ~Scene();

    private:
        entt::registry _registry;
    };
}

#endif