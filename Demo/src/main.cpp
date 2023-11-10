#include "../../E2DE/src/include/core.h"
#include "../../E2DE/src/include/Rendertest.h"
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

    std::cout << "POS X: " << pos.x << " POS Y: " << pos.y << '\n';

    e2e::dev::Renderable render(pos);
    e2e::dev::Renderable render2(pos * 2);

    while(!app.Terminate()){
        if(app.GetEventInstance()->Hold("t")){
            
        }

        app.update();

        app.BeginRender();

        render.render(app);
        render2.render(app);

        app.EndRender();
    }

    return 0;
}