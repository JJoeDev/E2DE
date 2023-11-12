#ifndef E2E_SCENE_H_
#define E2E_SCENE_H_

#include "../../Vendor/ECS/EnTT/src/entt/entt.hpp" // We can just say #include "entt.hpp" but vscodium can't find the header so I do this for now

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
