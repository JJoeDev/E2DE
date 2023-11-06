#include "../../E2DE/src/include/core.h"
#include <iostream>

int main(){
    e2e::Engine app("Hello DEMO", 500, 500);

    app.GetEventInstance()->NewMap("t");
    app.GetEventInstance()->BindKey("t", e2e::KEY_H, 1.0f);

    // app.GetEventManager().NewMap("test");
    // app.GetEventManager().BindKey("test", e2e::KEY_T, 1.0f);

    while(!app.Terminate()){
        if(app.GetEventInstance()->Released("t"))
            std::cout << "H RELEASED!\n";

        app.update();
        app.render();
    }

    return 0;
}