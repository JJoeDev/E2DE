#include "../../E2DE/src/include/core.h"
#include <iostream>

int main(){
    e2e::Engine app("Hello DEMO", 500, 500);

    app.GetEventManager().NewMap("test");
    app.GetEventManager().BindKey("test", e2e::KEY_T, 1.0f);

    while(!app.Terminate()){
        if(app.GetEventManager().Released("test"))
            std::cout << "TEST KEY VALUE: " << app.GetEventManager().GetValue("test");

        app.update();
        app.render();
    }

    return 0;
}