#include "Scene.h"
#include "Entity.h"
#include "../core.h"

namespace e2e{
    Scene::Scene(){
        
    }

    Scene::~Scene(){

    }

    Entity Scene::CreateEntity(){
        Entity ent = { _registry.create(), this };
        ent.AddComponent<TransformComponent>();
        return ent;
    }
}