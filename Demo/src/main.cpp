#include "../../E2DE/src/Engine/core.h"
#include "../../E2DE/src/Scene/Entity.h"
#include <iostream>

int main(){
    e2e::Engine app("Hello DEMO", 500, 500, SHOWN);

    app.GetEventInstance()->NewMap("t");
    app.GetEventInstance()->BindKey("t", e2e::KEYS::KEY_UP, 1.0f);
    app.GetEventInstance()->BindKey("t", e2e::KEYS::KEY_H, 0.35f);

    e2e::Vector pos(40.2f, 33.64f);
    e2e::Vector pos2(12.304f, 0.1f);

    pos += pos2; // X = 52,504 | Y = 33,74
    /*
        This supports the following instructions
        Vector + Vector
        Vector + float
        Vector - Vector
        Vector - float
        Vector * float
        Vector / float
        Vector == Vector
        Vector += Vector
        Vector += float
        Vector -= Vector
        Vector -= float
        Vector *= float
        Vector /= float
    */

    auto p = app.GetScene().CreateEntity();
    p.AddComponent<e2e::SpriteRendererComponent>(e2e::Vector4(160.0f, 255.0f, 72.5f, 255.0f));

    p.GetComponent<e2e::TransformComponent>().Position = e2e::Vector(20.0f, 20.0f);
    p.GetComponent<e2e::TransformComponent>().Scale = e2e::Vector(50.0f, 50.0f);

    while(!app.Terminate()){
        if(app.GetEventInstance()->Hold("t")){
            
        }

        app.update();
        app.Render();
    }

    return 0;
}