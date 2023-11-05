#include "../../E2DE/src/include/core.h"

int main(){
    e2e::Engine app("Hello DEMO", 500, 500);

    while(!app.Terminate()){
        app.update();
        app.render();
    }

    return 0;
}