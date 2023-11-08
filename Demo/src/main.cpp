#include "../../E2DE/src/include/core.h"
#include <iostream>

int main(){
    e2e::Engine app("Hello DEMO", 500, 500);

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

    while(!app.Terminate()){
        if(app.GetEventInstance()->Hold("t")){
            std::cout << "UP RELEASED!\n";
            std::cout << "VAL: " << app.GetEventInstance()->GetValue("t") << '\n';
        }

        std::cout << "FPS: " << 1000 / app.GetDeltaTime() << '\n';

        app.update();
        app.render();
    }

    return 0;
}